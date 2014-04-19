#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Weapon("Nature");

float query_worthiness() {
    if(determine_worthiness() > 500 && determine_worthiness() < 1000){
        return (to_float(determine_worthiness() * ((to_float(this_object()->query_craft())/20.0)+0.85)));
    }
    if(determine_worthiness() > 1000){
        return (determine_worthiness() * ((to_float(this_object()->query_craft())/20.0)+0.85) * 1.2);
    }
    else{
        return (to_float(determine_worthiness() * -1.0));
    }
}


void configure() {
        ::configure();
    add_hook(Mod_Hit, #'query_worthiness);
}