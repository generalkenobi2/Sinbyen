#include <Sinbyen.h>
#include <autonomon.h>

inherit "/std/autonomon";

void configure() {
        ::configure();
        alter_identity(Identity_Special_Names, ({ "SINBYEN_CITIZEN" }), Identity_Alter_Add);
        add_skill_points(Skill_Norska, 200);
        set_primary_language(Skill_Norska);
        set_area_control(True);
        set_omniscience(True);
}
