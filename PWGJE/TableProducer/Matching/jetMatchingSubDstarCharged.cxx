// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

// jet matching subtracted D* charged task
//
/// \author Nima Zardoshti <nima.zardoshti@cern.ch>

#include "PWGJE/TableProducer/Matching/jetMatchingSub.cxx"

#include "PWGJE/DataModel/Jet.h"
#include "PWGJE/DataModel/JetSubtraction.h"

#include <Framework/ASoA.h>
#include <Framework/AnalysisTask.h>
#include <Framework/ConfigContext.h>
#include <Framework/DataProcessorSpec.h>
#include <Framework/runDataProcessing.h>

#include <vector>

using DstarChargedJetMatchingSub = JetMatchingSub<soa::Join<aod::DstarChargedJets, aod::DstarChargedJetConstituents>,
                                                  soa::Join<aod::DstarChargedEventWiseSubtractedJets, aod::DstarChargedEventWiseSubtractedJetConstituents>,
                                                  aod::DstarChargedJetsMatchedToDstarChargedEventWiseSubtractedJets,
                                                  aod::DstarChargedEventWiseSubtractedJetsMatchedToDstarChargedJets,
                                                  aod::JTrackDstarSubs,
                                                  aod::CandidatesDstarData>;

WorkflowSpec defineDataProcessing(ConfigContext const& cfgc)
{
  std::vector<o2::framework::DataProcessorSpec> tasks;
  tasks.emplace_back(adaptAnalysisTask<DstarChargedJetMatchingSub>(cfgc, TaskName{"jet-matching-sub-dstar-ch"}));
  return WorkflowSpec{tasks};
}
