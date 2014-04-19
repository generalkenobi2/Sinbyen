#include <Sinbyen.h>
#include <room.h>
#include <service.h>

inherit Sinbyen_Room("Map_Base");

inherit "std/service";

Service_Functions(Map_Base)


void psych_script(object who, object owner, string what, int limb) {
        who->display(({
                "{{white}Dr. Driskul} leads you to the {{brown}chaise-style chaire} and states, \"Please take a seat.\"",
                "You tell the doctor your troubles.",
                "At the end of the session your psyche feels refreshed.",
        }));
}



void configure() {
	service::configure();
	Map_Base::configure();
	set_short("The Frowning Dwarf");
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is a quiet office",
		}),
		Description_Order                               : Description_Order_Extremely_Early,
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "chaise-style" }),
			Identity_Nouns                              : ({ "chair" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "is here for patients",
			}),
			Description_Order                           : Description_Order_Very_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Leather,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is plush and looks very comfortable",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Adjectives                         : ({ "comfy" }),
			Identity_Nouns                              : ({ "chair" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "sits behind the desk",
			}),
			Description_Order                           : Description_Order_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Leather,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "is well padded and looks very comfortable",
                }),
            ]),
        }),
	]));
	add_abstract_item(([
		Abstract_Item_Identity                          : ([
			Identity_Nouns                              : ({ "desk" }),
		]),
		Abstract_Item_Attach_Description                : ([
			Description_Type                            : Description_Type_Simple,
			Description_Content                         : ({
				({ 'a', 0 }), "sits in one corner of the office",
			}),
			Description_Order                           : Description_Order_Significantly_Early,
		]),
		Abstract_Item_Elements                          : ({
			([
				Element_Type                            : Material_Oak,
			]),
		}),
        Abstract_Item_Descriptions                      : ({
            ([
                Description_Type                        : Description_Type_Simple,
                Description_Content                     : ({
                    ({ 't', 0 }), "looks new and well polished",
                }),
            ]),
        }),
	]));
	set_services(([
                "listen"        : 150; "Soothing sounds will set your mind at ease."; 0; 30; 0,
                "talk"          : 375; "The doctor will listen to you talk your problems out."; 0; 80; 0,
                "counsel"       : 750; "The doctor will give you his opinion on what you should do to ease your mind."; 0; 180; 0,
                "hypnosis"      : 1500; "The doctor will regress you back to your childhood to learn the root of your problems."; 0; 340; 0,
                "mind blast"    : 3000; "The last resort in psycho-therapy.  A powerful force erases your mind of trauma.  The result is a clean and renewed psyche."; 0; 500; 0
        ]));
        set_service_script(#'psych_script);
        set_sign_language("norska");
        set_sign_introduction("Dr. Driskul can help you by:");
		set_contents(({
			Sinbyen_NPC("driskul"),
		}));
}

