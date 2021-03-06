//
// Copyright 2020 the authors listed in CONTRIBUTORS.md
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef PIR_CONTEXT_H_
#define PIR_CONTEXT_H_

#include "parameters.h"
#include "seal/seal.h"
#include "util/statusor.h"

namespace pir {

using ::private_join_and_compute::StatusOr;

using ::std::optional;
using ::std::shared_ptr;
using ::std::string;
using ::std::vector;

class PIRContext {
 public:
  /**
   * Creates a new context
   * @param[in] params PIR parameters
   * @returns InvalidArgument if the SEAL parameter deserialization fails
   **/
  static StatusOr<std::unique_ptr<PIRContext>> Create(
      std::shared_ptr<PIRParameters> /*params*/);
  /**
   * Returns an Evaluator instance
   **/
  std::shared_ptr<seal::Evaluator>& Evaluator() { return evaluator_; }

  /**
   * Returns the PIR parameters
   **/
  std::shared_ptr<PIRParameters>& Parameters() { return parameters_; }

  /**
   * Returns the database size
   **/
  size_t DBSize() { return parameters_->DBSize(); }

  /**
   * Returns the SEAL context
   **/
  std::shared_ptr<seal::SEALContext>& SEALContext() { return context_; }

  /**
   * Returns the encoder
   **/
  std::shared_ptr<seal::IntegerEncoder>& Encoder() { return encoder_; }

 private:
  PIRContext(std::shared_ptr<PIRParameters> /*params*/);

  shared_ptr<PIRParameters> parameters_;
  shared_ptr<seal::SEALContext> context_;
  shared_ptr<seal::Evaluator> evaluator_;
  shared_ptr<seal::IntegerEncoder> encoder_;
};

}  // namespace pir

#endif  // PIR_CONTEXT_H_
