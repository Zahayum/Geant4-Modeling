#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4Region.hh"
#include "G4ProductionCuts.hh"
#include "G4RegionStore.hh"

namespace tyone
{
    DetectorConstruction::DetectorConstruction()
    {
        this->margin_x = 5 * cm;
        this->margin_y = 5 * cm;
        this->margin_z = 5 * cm;

        this->source_surface_distance = 100 * cm;
    }

    DetectorConstruction::~DetectorConstruction()
    {
    }

    void DetectorConstruction::ConstructMaterials()
    {
        G4NistManager *nist = G4NistManager::Instance();
        this->world_material = nist->FindOrBuildMaterial("G4_AIR");
    }

    void DetectorConstruction::ComputeTranslations()
    {
        this->world_size_x = this->margin_x;
        this->world_size_y = this->margin_y;
        this->world_size_z = this->margin_z;

        this->source_translate = G4ThreeVector(0, 0, this->world_size_z / 2 - this->margin_z);
    }

    void DetectorConstruction::ConstructSolids()
    {
        this->world_solid = new G4Box("World", this->world_size_x / 2.0, this->world_size_y / 2.0, this->world_size_z / 2.0);
    }

    void DetectorConstruction::ConstructLogicals()
    {
        this->world_logic = new G4LogicalVolume(this->world_solid, this->world_material, "World");
    }

    void DetectorConstruction::ConstructPhysicals()
    {
        this->world_phys = new G4PVPlacement(
            nullptr,
            G4ThreeVector(),
            this->world_logic,
            "World",
            nullptr,
            false,
            0,
            true);
    }

    void DetectorConstruction::SetUpRegionsAndCuts()
    {
        // // Create region for film with special cuts
        // G4Region *filmRegion = new G4Region("FilmRegion");
        // this->film_logic->SetRegion(filmRegion);
        // filmRegion->AddRootLogicalVolume(this->film_logic);

        // // Set production cuts for film region (5 μm)
        // G4ProductionCuts *filmCuts = new G4ProductionCuts();
        // filmCuts->SetProductionCut(5 * um);
        // filmRegion->SetProductionCuts(filmCuts);
    }

    void DetectorConstruction::SetUpVisAttributes()
    {
        G4VisAttributes *world_vis = new G4VisAttributes();
        world_vis->SetForceWireframe(true);
        world_vis->SetVisibility(false);
        this->world_logic->SetVisAttributes(world_vis);
    }

    G4VPhysicalVolume *DetectorConstruction::Construct()
    {
        this->ConstructMaterials();
        this->ComputeTranslations();

        this->ConstructSolids();
        this->ConstructLogicals();
        this->ConstructPhysicals();
        this->SetUpRegionsAndCuts();

        this->SetUpVisAttributes();

        return this->world_phys;
    }
}
