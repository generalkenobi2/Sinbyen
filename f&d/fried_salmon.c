#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fried_Fillet");

status food_consumed(object who, object what) {
        who->add_attribute_modifier(([
            Modifier_Index      : Attribute_Dexterity,
            Modifier_Amount     : 20,  
            Modifier_Duration   : 300,
            Modifier_Add_Display    : ([
                Message_Content     : ({
                    0, ({ "feel", 0 }), "a bit more dexterous from dietary influences",
                }),
            ]),
            Modifier_Remove_Display : ([
                Message_Content     : ({
                    0, ({ "feel", 0 }), "a bit less dexterous as", ({ 'r', 0, "dietary influences" }), "fade",
                }),
            ]),
        ]));
}

void configure() {
        ::configure();
        add_description(({
            ({ 'v', 0 }), ({ "are", 0 }), 'a', "large fillet of salmon that has been breaded and deep fried",
        }));
        alter_identity(([
            Identity_Nouns          : ({ "fillet of salmon", "fillet", "salmon" }),
            Identity_Adjectives     : ({ "deep fried" }),
        ]));
        set_heal(5);
        set_consume_func(#'food_consumed);
        set_shape(([
            Shape_Type              : Geometry_Block,
            Shape_Length            : 3.0,
            Shape_Width             : 1.0,
            Shape_Height            : 0.4,
        ]));
        set_servings(4);
}
