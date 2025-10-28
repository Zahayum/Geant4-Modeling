#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

namespace tyone
{

  SteppingAction::SteppingAction()
  {
  }

  SteppingAction::~SteppingAction()
  {
  }

  void SteppingAction::UserSteppingAction(const G4Step *step)
  {
  }
}
