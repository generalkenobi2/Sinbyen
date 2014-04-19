#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

mixed query_room_desc() {
    mixed array content = ({
        ({ 'a', this_object() }), "is nearby.",
    });
    return Description(([
        Description_Type                                : Description_Type_Simple,
        Description_Order                               : Description_Order_Very_Slightly_Early,
        Description_Content                             : content,
    ]));
}
void configure() {
    ::configure();
    thing()->set_thing_type(Thing_Type_Bed);
    add_description(Description_Type_Generic);
    set_craft(Craft_Excellent);
    add_proportion(([
        Element_Type             : random_element(([     Material_Pine        :    10,
                                                        Material_Oak        :    6,
                                                        Material_Ironwood    :    1,
                                                        Material_Ebony        :    3,
                                                    ])),
        Element_Proportion       : 1.0,
    ]));
    set_shape(([
        Shape_Type               : Geometry_Box,
        Shape_Length             : 22.0,
        Shape_Width              : 6.5, 
        Shape_Height             : 4.5,
        Shape_Thickness          : 1.0,
    ])); 
}
