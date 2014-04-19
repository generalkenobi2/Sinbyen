#include <item.h>

inherit "/std/remains";

descriptor remains_element_process(descriptor dxr) {
        dxr = ::remains_element_process(dxr);
        if(Element_Query(dxr, Element_Part) != Part_Bulk)
                return 0;
        descriptor out = copy(dxr);
        Element_Flag_On(out, Element_Flag_Suppress_Race);
        return out;
}


void configure() {
        ::configure();
        add_description(Description_Type_Generic);
        alter_identity(([    
            Identity_Nouns                : ({({"lump of flesh and bone", 0, Seeable_Order_Early }),({ "bone", 0, Seeable_Order_Early }), ({"flesh", 0, Seeable_Order_Early })}),
            Identity_Flags                : Identity_Flag_Suppress_Elements,
        ]));
        set_remains_decay(True);
        set_remains_create_message(({({ 's', 0, "%l" }), ({ "tear", "%l" }), "away from", ({ 'r', 0, "body" }) }));
        set_remains_decay_away_message(({ 0, ({ "dissolve", 0 }), "slowly into the air" }));

}
