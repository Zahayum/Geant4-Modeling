#ifndef TyOneRunAction_h
#define TyOneRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"

class G4Run;

namespace tyone
{

  class RunAction : public G4UserRunAction
  {
  public:
    RunAction();
    ~RunAction() override;

    void BeginOfRunAction(const G4Run *) override;
    void EndOfRunAction(const G4Run *) override;
  };

}

#endif
