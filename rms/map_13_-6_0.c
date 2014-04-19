#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("a large bedroom");
	set_exit_flags(Direction_West, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_North);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this appears to be the master bedroom of the Rageborn family manor",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	add_description(([
		Description_Type                                : Description_Type_Viewer_Condition,
		Description_Index                               : ([
			Condition_Type_Code                         : Condition_Type_Daytime,
		]),
		Description_Content                             : ({
			"The open alcove floods the room with {{sparkling white}natural light}",
		}),
		Description_Order                               : Description_Order_Slightly_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "bed" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "sits against the south wall here",
			}),
			Description_Order                           : Description_Order_Early,
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
                    ({ 't', 0 }), "is set with many ornate carvings depicting gryphons",
                }),
            ]),
        }),
	]));
	
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "bay windows", "window" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'n', 0 }), "sit in an alcove, overlooking the street"
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Glass,
                Element_Color                           : "clear",
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "are made of large, single panes, rather than many smaller panes",
                }),
            ]),
        }),
	]));
	add_contents(({
			Sinbyen_Misc("fireplace"),
		}));
}
