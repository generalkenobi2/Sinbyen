#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Fillet");

status food_consumed(object who, object what) {
        who->add_skill_modifier(([
            Modifier_Index      : Skill_Hardiness,
            Modifier_Amount     : 30,  
            Modifier_Duration   : 300,
        ]));
}

void configure() {
    ::configure();
        add_description("a huge fillet of seabass");
        alter_identity(([
            Identity_Nouns          : ({ "fillet of seabass", "fillet", "seabass" }),
        ]));
        set_food(24);
        set_heal(5);
        set_consume_func(#'food_consumed);
        set_shape(([
            Shape_Type              : Geometry_Block,
            Shape_Length            : 5.0,
            Shape_Width             : 1.3,
            Shape_Height            : 0.4,
        ]));
        set_servings(7);
}
