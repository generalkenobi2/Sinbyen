#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("A Crimson Fist Training Room");
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_East, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_West);
	add_exit(Direction_South);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this appears to be a small archery range",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity 							: ([
			Identity_Nouns                              : ({ "racks" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "along the wall hold several unstrung bows"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Oak,
				Element_Color                           : "red",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "appear nicked and show signs of extended use",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "long" }),
			Identity_Nouns                              : ({ "bench" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "stretches from one side of the room to the other",
			}),
			Description_Order                           : Description_Order_Significantly_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Pine,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "provides ample space for one to set the bow down between shots,",
                    " and offer convenient storage of arrows for those that lack a quiver",
                }),
            ]),
        }),
	]));
}
