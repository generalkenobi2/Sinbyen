#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fried_Fillet");

status food_consumed(object who, object what) {
        who->add_attribute_modifier(([
            Modifier_Index      : Attribute_Charisma,
            Modifier_Amount     : 20,  
            Modifier_Duration   : 300,
            Modifier_Add_Display    : ([
                Message_Content     : ({
                    0, ({ "feel", 0 }), "a bit more charismatic from dietary influences",
                }),
            ]),
            Modifier_Remove_Display : ([
                Message_Content     : ({
                    0, ({ "feel", 0 }), "a bit less charismatic as", ({ 'r', 0, "dietary influences" }), "fade",
                }),
            ]),
        ]));
}

void configure() {
        ::configure();
        add_description(({
            ({ 'v', 0 }), ({ "are", 0 }), 'a', "large fillet of snapper that has been breaded and deep fried",
        }));
        alter_identity(([
            Identity_Nouns          : ({ "fillet of snapper", "fillet", "snapper" }),
            Identity_Adjectives     : ({ "deep fried" }),
        ]));
        set_heal(5);
        set_consume_func(#'food_consumed);
        set_shape(([
            Shape_Type              : Geometry_Block,
            Shape_Length            : 3.0,
            Shape_Width             : 1.6,
            Shape_Height            : 0.4,
        ]));
        set_servings(5);
}
