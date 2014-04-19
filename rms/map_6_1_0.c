#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("Fierro's Elemental Armoury");
	set_exit_flags(Direction_Northwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southwest, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Northeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	set_exit_flags(Direction_Southeast, Exit_Flag_Inobvious | Exit_Flag_Requires_Intangibility);
	add_exit(Direction_East);
	add_exit(Direction_West);
	add_exit(Direction_North);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is the one and only Elemental Armoury.  The only place one can find armour that not only protects from, but doles out elemental contact damage.  The shop appears to still be under construction.",
			
		}),
		Description_Order                               : Description_Order_Early,
	]));
	
//	add_abstract_item(([
//		Abstract_Item_Identity                          : ([
//			Identity_Nouns                              : ({ "racks", "displays", }),
//		]),
//		Abstract_Item_Attach_Description                : ([
//			Description_Type                            : Description_Type_Simple,
//			Description_Content                         : ({
//			"there are", ({ 'n', 0 }), "and {{clear}displays} of armours that gleam with differnt colors.",
//			}),
//			Description_Order                           : Description_Order_Early,
//		]),
//		Abstract_Item_Elements                          : ({
//			([
//				Element_Type                            : Material_Titanium,
//			]),
//		}),
//       Abstract_Item_Descriptions                      : ({
//          ([
//                Description_Type                        : Description_Type_Simple,
//               Description_Content                     : ({
//                    ({ 't', 0 }), "seem to display the less volitile armours, some of these glow a {{dark orange}dim orange},",
//                    "and others a {{light blue}dim blue}.  The {{clear}display cases} shield the customers from suits with",
//					"the more dangerous effects. One {{clear}display} contains a {{fire}suit} that occasionally emits {{fiery}sparks} and tiny {{fiery}flames}.",
//               }),
//            ]),
//       }),
//	]));

set_contents(({
		Sinbyen_NPC("fierro_vandego"),
	}));

}
