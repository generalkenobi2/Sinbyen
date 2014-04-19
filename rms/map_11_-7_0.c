#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("a greenhouse");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_North);
	add_exit(Direction_East);
	add_exit(Direction_South);
	add_exit(Direction_West);
	add_exit(Direction_Southwest);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"the area is absolutely alive with {{dark green}greenery}",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			Description(([
			    Description_Type                        : Description_Type_Viewer_Condition,
                Description_Index                       : ([
                    Condition_Type_Code                 : Condition_Type_Smell,
                ]),
                Description_Content                     : "the area smells fresh like a forest",
			])),
		}),
		Description_Order                               : Description_Order_Early,
	]));
	
}
