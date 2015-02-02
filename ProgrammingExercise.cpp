// ProgrammingExercise.cpp
// Taking three dimensions as input, calculate the volume and floor area of a room and calculate
// the amount of paint required.
//

#include <iostream>
#include <cfloat>

// Keeping this simple, not creating a set of classes, so pre-define functions and variables here
bool GetArgs(int argc, char *argv[]);
bool ValidateArgs();
float CalculateFloorArea(void);
float CalculateWallArea(void);
float CalculateVolume(void);
void Usage();
float fWidth;
float fLength;
float fHeight;

using namespace std;

int main(int argc, char* argv[])
{
    if (false == GetArgs(argc, argv))
    {
        exit(-1);
    }    
    if (false == ValidateArgs())
    {
        exit(-1);
    }   
    cout << "Room dimensions - Width: " << fWidth << " Length: " << fLength << " Height: " << fHeight << " units" << endl; 
    float fWallArea = CalculateWallArea(); 
    float fFloorArea = CalculateFloorArea(); 
    float fRoomVolume = CalculateVolume(); 
    cout << "Wall Area: " << fWallArea << " units squared" <<endl;
    cout << "Floor Area: " << fFloorArea << " units squared"  << endl;
    cout << "Room Volume: " << fRoomVolume << " units cubed"  << endl;

	return 0;
}
// function to calculate the wall area of a room, 
// No inputs - uses member variables
// output float fArea - units are not defined
float CalculateWallArea(void)
{
    float fArea = ((fWidth * fHeight)*2) + ((fLength * fHeight)*2) ;
    return fArea;
}
// function to calculate the floor area of a room, 
// No inputs - uses member variables
// output float fArea - units are not defined
float CalculateFloorArea(void)
{
    float fArea = (fWidth * fLength);
    return fArea;
}
// function to calculate the volume of a room, 
// No inputs - uses member variables
// output float fVolume - units are not defined
float CalculateVolume(void)
{
    float fVolume = (fWidth * fHeight* fLength);
    return fVolume;
}
// Extract command line arguments, which will contain the room dimensions
// Input size of arg list and array of args
// output - boolean true if sufficient args correctly set
//                  false if some args missing or invalid
bool GetArgs(int argc, char *argv[])
{
    int i=1;
    bool bOK = true;
    unsigned int ui_term_count = 0;

    while(i<=argc-1)
    {
        if (argv[i][0] != '-' && argv[i][0] != '/')
        {
            cerr << "Can't understand " << argv[i] << ". Have you missed a '-' or '/' ?" << endl;
            bOK = false;
            Usage();
            break;
        }
        switch(argv[i][1])
        {
            case 'u':
                Usage();
                bOK = false;
                break;
            case 'w':
                {
                    if (i+1 > argc-1)
                    {
                        cerr << "ERROR: Missing argument of -w.\n\n";
                        Usage();
                        return false;
                    }
                    string sWidth = argv[i+1];
                    fWidth = static_cast<float>(atof(sWidth.c_str()));
                    i++;
                }
                break;
            case 'h':
                {
                    if (i+1 > argc-1)
                    {
                        cerr << "ERROR: Missing argument of -h.\n\n";
                        Usage();
                        return false;
                    }
                    string sHeight = argv[i+1];
                    fHeight = static_cast<float>(atof(sHeight.c_str()));
                    i++;
                }
                break;
            case 'l':
                {
                    if (i+1 > argc-1)
                    {
                        cerr << "ERROR: Missing argument of -l.\n\n";
                        Usage();
                        return false;
                    }
                    string sLength = argv[i+1];
                    fLength = static_cast<float>(atof(sLength.c_str()));
                   i++;
                }
                break;
            default:
                cerr << "Can't understand " << argv[i] << endl;
                Usage();
                bOK = false;
                break;
        }
        i++;
    }

    return bOK;
}
// Function to validate input arguments - initially all values > 0 and < FLT_MAX
// No inputs as uses member variables
// Output boolean - true if all dimensions valid
//                  false if any dimension <=0 or >= FLT_MAX
bool ValidateArgs()
{
    bool bOK = false;
    if(fWidth <=0 || fLength <=0 || fHeight <=0)
    {
        cout << "ERROR: All values should be > 0" <<endl;
    }
    else if(fWidth >= FLT_MAX || fLength >= FLT_MAX || fHeight >= FLT_MAX)
    {
        cout << "ERROR: All values should be < FLT_MAX" <<endl;
    }
    else
    {
        bOK = true;
    }
    return bOK;
}

// Display usage instructions
void Usage()
{
    cerr << "\nProgramming Exercise\n\n";
    cerr << "Usage: " << " -w <float> \"room width\"\n";
    cerr << "Usage: " << " -l <float> \"room length\"\n";
    cerr << "Usage: " << " -h <float> \"room height\"\n";
    cerr << "Usage: " << " Note that units are free\n";
}