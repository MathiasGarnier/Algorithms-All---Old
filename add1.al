/**
 * @package null
 * @subpackage null
 * @since VerifierYapix 0.0.1
 * @Author Yapix [DEV-MASTER && CREATOR]
 * @AltesVersion Alpha 0.000.001
 * @ApiVersion Beta 0.0.1
 * @UserName 5850-df7a-b25f-47e6-9fc2-6630-f513-81f2
 * @Description ;)
 * @DocRepertory N
 * @AlgAltes Y
 * @AutoImport N
 */

//The goal of this program is simply add 1 to the value obtained !

AlgAltes

/*
	AlgAltes is the process include in the Altes-Lang for make work the language. This is not compulsory to do with hand !
	Sometimes it is even advisable ! Pay attention with this ! The compiler can do it alone ! ;) Documentation for this is online !
							[Warning there might be problems when compiling !]
*/

{ //Open
	DEFINE included(sourcePath::file[file() << [getFileName()], sdkFile()]);	//"included" object is used to use the "#include" keyword !
		//If "included" fonction is not defined the keywords "#include" is no use !	
		def (included): 	//Definition of "included" object !
			//The "def" keyword is compulsory !
			sc sourcePath();    //"sc" equals Source Control, definition of "sourcePath" fonction and object (but all is object in Altes)!
				//The "sc" object is beforehand define, this is impossible to recreate this object or modify this !
				sourcePath file();    //Utilization of "sourcePath" object for create "file" fonction and object !
					//"sourcePath" before "file()" is compulsory ! With the utilization of "sourcePath" the "file" object and fonction is create and it serves !
					file getFileName();    //Utlization of "file" object for create "getFileName" fonction and object !
						//"file" before "getFileName()" is compulsory ! WIth the utilization of "file" the "getFileName" object and fonction is create and it serves ! 		
				sourcePath sdkFile();    //Utilization of "sourcePath" object for create "sdkFile" fonction and object ! 
					//"sourcePath" befoire "sdkFile()" is compulsory ! With the utilization of "sourcePaht" the "sdkFile" object and fonction is create and it serves !
#include client:system:object:math:pow:*;	//The repository of "pow" is used to math fonction power (x, y) !
	//Without "included" fonction and object this line is no use ! Include of the fonction of pow in sc/client/system/object/math/pow/*
	DEFINE int(number.between[int.[getMinValue(-n)] && [getMaxValue(n)]]);    //"int" object is used to define an integer number between the integer maximum and minimum !
		//If "int" fonction is not defined the left-over will not work !
		def (int):    //Definition of "int" object !
			//The "def" keyword is compulsory !
			nb number(n);    //"nb" equals number, definition of "number->n" object and fonction !
				//The "nb" object is beforehand define, this is impossible to recreate this object or modify this !
				number n();    //Natural integer
					//Utilization of "number" object for create "n()" number !
				number between(-n <-> n);	//Utilization of "number" object for create "between" fonction and object !
					//This is for the defference of natural max and min integer value
					number getMinValue(getMaxValue() - (pow(getMaxValue, getMaxValue) - 1));    //This is for define min value of an integer number !
						//2 147 483 647 - (2 147 483 647 * 2 147 483 647) -1
					number getMaxValue(getMinValue() + (pow(getMinValue, getMinValue) + 1));    //This is for define max value of an integer number !
						//2 147 483 647 + (2 147 483 647 * 2 147 483 647) + 1

} //Close

#import Altes:BinLibFile:altdio.bin 	//Altdio.bin is the source control of Altes
#import Altes:Compiler:altcompil.bin 	//Altcompil.bin is the compiler of the source control of Altes
