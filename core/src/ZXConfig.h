/*
* Copyright 2018 Axel Waggershauser
*/
// SPDX-License-Identifier: Apache-2.0

#pragma once

// Thread local or static memory may be used to reduce the number of (re-)allocations of temporary variables
// in e.g. the HistogramBinarizer. The default is thread_local, which is the best option for performance and safety in most cases. If
// your platform doesn't support thread_local, you can switch to static, but be aware that this makes the code not thread safe.
// For Windows in Visual Studio 2019 on Intel 64-bit using thread_local causes a dependency to VCRUNTIME140_1.dll, so you need 2019
// runtime DLLs instead of only 2015 version.
// The ESP32 firmware (Zephyr/Xtensa) has no thread-local storage support and
// the QR decoder runs single-threaded, so use plain static storage.
#define ZX_THREAD_LOCAL static // '' (nothing), 'thread_local' or 'static'

// The Galois Field abstractions used in Reed-Solomon error correction code use more memory than required to improve performance (20% - 100%).
// If RAM is scarce, you can define LIBRSCPP_SAVE_MEMORY to reduce memory usage. The effect is a few kB big.
// #define LIBRSCPP_SAVE_MEMORY
