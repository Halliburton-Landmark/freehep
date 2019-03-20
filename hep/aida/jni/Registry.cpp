
#include "FreeHepTypes.h"

#include "Registry.h"

using namespace JAIDA;
using namespace std;

map<jlong, const void*> Registry::cref;
map<const void*, jobject> Registry::jref;
map<const void*, jclass> Registry::jrefClass;
Registry* Registry::registry;
bool Registry::debug;
