#include <Liathyr.h>
#include <item.h>

inherit "/std/item";

void configure() {
    ::configure();
    alter_identity(Identity_Nouns, ({ "chair" }));
    add_description(Description_Type_Generic);
    set_craft(Craft_Fair);
    set_shape(([
        Shape_Type               : Geometry_Box,
        Shape_Length             : 0.2,
        Shape_Width              : 4.5, 
        Shape_Height             : 8.7,
        Shape_Thickness          : 1.0,
    ])); 
    add_proportion(([
        Element_Type             :  random_element(([    
                                        Material_Pine       :    10,
                                        Material_Oak        :    6,
                                        Material_Ironwood   :    1,
                                        Material_Ebony      :    3,
                                    ])),
        Element_Proportion       : 1.0,
    ]));
}
