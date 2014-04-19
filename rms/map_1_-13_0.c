#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("the southern gatehouses");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_South, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_West, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
}
