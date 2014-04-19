#include <item.h>

inherit "/std/comestible";

void configure() {
        ::configure();
        set_creator("kenobi");
        alter_identity(Identity_Type, Identity_Type_Unit);
        add_description(Description_Type_Generic);
        set_shape(([
            Shape_Type              : Geometry_Sphere,
            Shape_Radius            : 1.3,
        ]));
        set_comestible_type("food");
        set_portable(True);
        set_restore_hit_points(1);
        set_restore_spell_points(1);
        set_restore_endurance(1);
        set_food(3);
        set_servings(3);
        set_drink(1);
        set_pleasure(0.90);
        set_consume_message("Its flavor is sweet and juicy.");
        add_proportion(([
            Element_Type             : Material_Watermelon,
            Element_Proportion       : 1.0,
        ]));
}
