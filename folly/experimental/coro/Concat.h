/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <folly/experimental/coro/AsyncGenerator.h>

namespace folly {
namespace coro {

// Concatenate the values from multiple streams into a single stream such
// that each stream is exhausted before the next one begins.
//
// The input is a variadic list of AsyncGenerators, where each input has the
// same Reference and Value types.
//
// The output is a single AsyncGenerator over all of the input generators.
//
// Example:
//  AsyncGenerator<int> stream();
//
//  Task<int> consumer() {
//    auto values = concat(stream(), stream(), stream());
//
//    int result = 0;
//    while (auto item = co_await values.next()) {
//      result += *item;
//    }
//
//    return result;
//  }
template <typename Head, typename... Tail>
detail::enable_if_async_generator_t<Head> concat(Head head, Tail... tail);

} // namespace coro
} // namespace folly

#include <folly/experimental/coro/Concat-inl.h>
