/*
 * Copyright (C) 2011 Daniel Himmelein
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "android/os/SerialExecutor.h"
#include "android/os/Handler.h"
#include "android/os/Message.h"

namespace android {
namespace os {

SerialExecutor::SerialExecutor() :
	mHandler(NULL) {
	mLooperThread.start();
	mHandler = mLooperThread.getHandler();
}

SerialExecutor::~SerialExecutor() {
	mLooperThread.getLooper()->quit();
	mLooperThread.join();
}

void SerialExecutor::execute(Runnable& runnable) {
	mHandler->obtainMessage(runnable).sendToTarget();
}

bool SerialExecutor::cancel(Runnable& runnable) {
	return mHandler->removeCallbacks(&runnable);
}

} /* namespace os */
} /* namespace android */
