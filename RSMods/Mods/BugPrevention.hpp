#pragma once

#include "Windows.h"
#include <iostream>

#include "../MemUtil.hpp"
#include "../Offsets.hpp"

namespace BugPrevention {
	void PreventOculusCrash();
	void PreventStuckTone();
}