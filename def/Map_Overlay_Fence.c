#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void set_fence_direction(mixed dir) {
        object def = Direction(dir);
        int code = def->query_direction_code();
        add_map_feature_abstract_item(([
                Abstract_Item_Identity           : ([
                        Identity_Adjectives          : ({ "galvanized" }),
                        Identity_Nouns               : ({ "fence" }),
                ]),
                Abstract_Item_Elements           : ({ Material_Steel }),
                Abstract_Item_Descriptions       : ({({
                        ({ 't', 0 }), "separates a forested area from the rest of the city",
                })}),
        ]));
        add_map_feature_exit_obscure(code, 0.40);
        add_map_feature_access_override(code, Move_Access_Tunnel);
}
