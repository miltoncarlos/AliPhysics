/*
 * AliFemtoDreamCascadeCuts.h
 *
 *  Created on: Jan 11, 2018
 *      Author: gu74req
 */

#ifndef ALIFEMTODREAMCASCADECUTS_H_
#define ALIFEMTODREAMCASCADECUTS_H_
#include "Rtypes.h"
#include "TList.h"
#include "AliMCEvent.h"
#include "AliFemtoDreamCascade.h"
#include "AliFemtoDreamCascadeHist.h"
#include "AliFemtoDreamv0MCHist.h"
#include "AliFemtoDreamTrackCuts.h"
class AliFemtoDreamCascadeCuts {
 public:
  AliFemtoDreamCascadeCuts();
  virtual ~AliFemtoDreamCascadeCuts();
  static AliFemtoDreamCascadeCuts *XiCuts(bool isMC,bool contribSplitting);
  void Setv0Negcuts(AliFemtoDreamTrackCuts *cuts){fNegCuts=cuts;};
  void Setv0PosCuts(AliFemtoDreamTrackCuts *cuts){fPosCuts=cuts;};
  void SetBachCuts(AliFemtoDreamTrackCuts *cuts){fBachCuts=cuts;};
  void SetIsMonteCarlo(bool isMC){fMCData=isMC;};
  bool GetIsMonteCarlo() {return fMCData;};
  void SetContributionSplitting(bool contrSplit){
    fContribSplitting=contrSplit;};
  void SetXiMassRange(float mass,float width){
    fcutXiMass=true;fXiMass=mass;fXiMassWidth=width;};
  void SetXiCharge(int charge){fcutXiCharge=true;fXiCharge=charge;}
  void SetCutXiDaughterDCA(float maxDCA){
    fcutDCAXiDaug=true;fMaxDCAXiDaug=maxDCA;};
  void SetCutXiMinDistBachToPrimVtx(float minDist){
    fcutMinDistVtxBach=true;fMinDistVtxBach=minDist;};
  void SetCutXiCPA(float cpa){fcutCPAXi=true;fCPAXi=cpa;};
  void SetCutXiTransverseRadius(float minRad,float maxRad){
    fcutXiTransRadius=true;fMinXiTransRadius=minRad;fMaxXiTransRadius=maxRad;}
  void Setv0MassRange(float mass,float width){
    fcutv0Mass=true;fv0Mass=mass;fv0Width=width;}
  void SetCutv0MaxDaughterDCA(float maxDCA){
    fcutv0MaxDCADaug=true;fv0MaxDCADaug=maxDCA;}
  void SetCutv0CPA(float CPA){
    fcutCPAv0=true;fCPAv0=CPA;}
  void SetCutv0TransverseRadius(float minRad,float maxRad){
    fcutv0TransRadius=true;fMinv0TransRadius=minRad;fMaxv0TransRadius=maxRad;}
  void SetCutv0MinDistToPrimVtx(float minDist){
    fcutv0MinDistVtx=true;fv0MinDistVtx=minDist;}
  void SetCutv0MinDaugDistToPrimVtx(float minDist){
    fcutv0DaugMinDistVtx=true;fv0DaugMinDistVtx=minDist;};
  void SetRejectOmegas(float mass, float width) {
    fRejOmega=true;fRejOmegaMass=mass;fRejOmegaWidth=width;
  }
  void SetPDGCodeCasc(int PDG){fPDGCasc=PDG;};
  int GetPDGCodeCasc(){return fPDGCasc;};
  void SetPDGCodePosDaug(int PDG){fPDGPosDaug=PDG;};
  int GetPDGCodePosDaug(){return fPDGPosDaug;};
  void SetPDGCodeNegDaug(int PDG){fPDGNegDaug=PDG;};
  int GetPDGCodeNegDaug(){return fPDGNegDaug;};
  void SetPDGCodeBach(int PDG){fPDGBachDaug=PDG;};
  int GetPDGCodeBach(){return fPDGBachDaug;};
  void SetPDGCodev0(int PDG) {fPDGv0=PDG;};
  int GetPDGv0() {return fPDGv0;};
  TString ClassName()const{return "AliFemtoDreamCascadeCuts";};
  void Init(bool MinimalBooking);
  bool isSelected(AliFemtoDreamCascade *casc);
  void BookQA(AliFemtoDreamCascade *casc);
  void BookMCQA(AliFemtoDreamCascade *casc);
  void FillMCContributions(AliFemtoDreamCascade *casc);
  TList *GetQAHists() {return fHistList;};
  TList *GetMCQAHists() {return fMCHistList;};
 private:
  AliFemtoDreamCascadeHist *fHist;            //!
  AliFemtoDreamv0MCHist *fMCHist;             //!
  AliFemtoDreamTrackCuts *fNegCuts;
  AliFemtoDreamTrackCuts *fPosCuts;
  AliFemtoDreamTrackCuts *fBachCuts;
  TList *fHistList;
  TList *fMCHistList;
  bool fMinimalBooking;
  bool fMCData;
  bool fContribSplitting;
  bool fcutXiMass;
  float fXiMass;
  float fXiMassWidth;
  bool fcutXiCharge;
  int fXiCharge;
  bool fcutDCAXiDaug;
  float fMaxDCAXiDaug;
  bool fcutMinDistVtxBach;
  float fMinDistVtxBach;
  bool fcutCPAXi;
  float fCPAXi;
  bool fcutXiTransRadius;
  float fMinXiTransRadius;
  float fMaxXiTransRadius;
  bool fcutv0Mass;
  float fv0Mass;
  float fv0Width;
  bool fcutv0MaxDCADaug;
  float fv0MaxDCADaug;
  bool fcutCPAv0;
  float fCPAv0;
  bool fcutv0TransRadius;
  float fMinv0TransRadius;
  float fMaxv0TransRadius;
  bool fcutv0MinDistVtx;
  float fv0MinDistVtx;
  bool fcutv0DaugMinDistVtx;
  float fv0DaugMinDistVtx;
  bool fRejOmega;
  float fRejOmegaMass;
  float fRejOmegaWidth;
  int fPDGCasc;
  int fPDGv0;
  int fPDGPosDaug;
  int fPDGNegDaug;
  int fPDGBachDaug;
  ClassDef(AliFemtoDreamCascadeCuts,2)
};

#endif /* ALIFEMTODREAMCASCADECUTS_H_ */
