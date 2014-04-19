#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fillet");

status food_consumed(object who, object what) {
        who->add_skill_modifier(([
            Modifier_Index      : Skill_Shield,
            Modifier_Amount     : 30,  
            Modifier_Duration   : 300,
            Modifier_Add_Display    : ([
                Message_Content     : ({
                    0, ({ "feel", 0 }), "a bit more skilled from dietary influences",
                }),
            ]),
            Modifier_Remove_Display : ([
                Message_Content     : ({
                    0, ({ "feel", 0 }), "a bit less skilled as", ({ 'r', 0, "dietery influences"}), "fade",
                }),
            ]),
        ]));
}


void configure() {
    ::configure();
        add_description("a massive fillet of tuna");
        alter_identity(([
            Identity_Nouns          : ({ "fillet of tuna", "fillet", "tuna" }),
        ]));
        set_food(24);
        set_heal(10);
        set_consume_func(#'food_consumed);
        set_shape(([
            Shape_Type              : Geometry_Block,
            Shape_Length            : 14.0,
            Shape_Width             : 2.5,
            Shape_Height            : 0.6,
        ]));
        set_servings(12);
}
