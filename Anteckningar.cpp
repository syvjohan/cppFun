//Ny lektion!
class String {
	int size;
	char &data = 0;
}

data = new char[]

String &operator = (const String & vhs);
if (&vhs != this) {
delete data[];
	if (vhs->size == 0) {
		data = nullptr;
		size = 0;
	} else {
		data = new char [vhs->size];
		size = vhs->size;
		return *this;
	}
}


operator = 
String( string & )
String (string && vhs) {
	data = vhs.data;
	size = vhs.size;
	vhs.data = nunllptr;
	vhs.size = 0;
}

//Ett bättre sätt att göra swap på!
String Foo (string x, String y) {
	String temp;
	//std::move gör om x och y till rvalue.
	temp = append(Std::move(x), std::mvoe(y));

	return temp;
}

//Vid deep copy används =, tillexempel: String s = String s2.


//Ny lektion!
A a; //Icke initialiserat objekt.
A a{} //Initialiserat objekt. (Kallar på default konstruktorn). A a{}; B b{}; a = b;
//A a{} är detsamma som A a = A();
//Destruktorn ska vara virtual om det finns en arvshierki där objektet ärvs av ett annat objekt.
//Vid static_cast kontrollerar kompilatorn om typen som objektet ska ändras till är kompatibelt med det gamla.
//Vid dynamic_cast kontrollerar kompilatorn inte om den gamla och den nya typen som objektet ska kastas till är kompatibla med varandra, ger inga 
//kompilator fel.
//reinterpret_cast, använd aldrig.
//const_cast tar bort const i resultatet och tvärt om ifall input inte är const då läggs const till i resultatet.
//C casten (double) i är en blandning mellan static och dynamic cast.
//



