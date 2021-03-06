/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef CORE_VALIDATION_CONSENSUSEVENTVALIDATOR_HPP_
#define CORE_VALIDATION_CONSENSUSEVENTVALIDATOR_HPP_

#include "../consensus/consensus_event.hpp"
#include <type_traits>

namespace consensus_event_validator {

  template <
    typename T,
    std::enable_if_t<
            std::is_base_of<abstract_transaction::AbstractTransaction, T>::value, std::nullptr_t
    > = nullptr
  >
  using Abs = T;

  bool isValid(const consensus_event::ConsensusEvent<Abs>& event) {

  };

  bool isValid(const std::string& event) {
     return true;
  };

    bool signaturesAreValid(const consensus_event::ConsensusEvent<Abs>& event) {
      for (auto sig : event.signatures) {
          if (!consensus_event_validator::isValid(sig)) {
              return false;
          }
      }
  };

};  // namespace consensus_event_validator

#endif  // CORE_VALIDATION_CONSENSUSEVENTVALIDATOR_HPP_
