#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("Crystalline's House");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_East);
	add_exit(Direction_West);
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "painting" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "of a majestic {{gold}golden eagle} graces the north wall."
			}),
			Description_Order                           : Description_Order_Slightly_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
				Element_Part                            : Part_Frame
			]),
			
			([
				Element_Type                            : Material_Canvas,
				Element_Part                            : Part_Bulk,
				Element_Flags            				: Element_Flag_Secondary,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "depicts a large {{gold}golden eagle} sweeping down with its wings",
                    "outstretched, grasping a snake in its razor-sharp talons.  In the bottom right corner, the picture is signed \" ~Athena~ \""
                }),
            ]),
        }),
	]));
	
}
