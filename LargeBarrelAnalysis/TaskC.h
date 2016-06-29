/**
 *  @copyright Copyright 2016 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  @file TaskC.h
 */

#ifndef TASKC_H 
#define TASKC_H 

#include "JPetTask/JPetTask.h"
#include "JPetHit/JPetHit.h"
#include "JPetRawSignal/JPetRawSignal.h"

class JPetWriter;

class TaskC:public JPetTask {
 public:
  TaskC(const char * name, const char * description);
  virtual void init(const JPetTaskInterface::Options& opts);
  virtual void exec();
  virtual void terminate();
  virtual void setWriter(JPetWriter* writer) {fWriter =writer;}
 protected:
  std::vector<JPetHit> createHits(std::vector<JPetRawSignal>& signals);
  void saveHits(std::vector<JPetHit> hits);

  std::vector<JPetRawSignal> fSignals;
  
  JPetWriter* fWriter;
  
  //ClassDef(TaskC, 1);
};
#endif /*  !TASKD_H */
