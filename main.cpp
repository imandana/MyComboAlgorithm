#include <iostream>
#include <vector>

int comboRow = 0;
int input = 0;
int lastInput = 0;

void BreakCombo()
{
    std::cout << "Combo Breaked \n" << std::endl;
    comboRow = 0;
    input = 0;
    lastInput = 0;
}

// Combo 1: 0 0 0 0 
void PunchA1()
{
    std::cout << "PunchA1 " << std::endl;
    comboRow++;
}

void PunchA2()
{
    std::cout << "PunchA2 " << std::endl;
    comboRow++;
}

void PunchA3()
{
    std::cout << "PunchA3 " << std::endl;
    comboRow++;
}

void PunchA4()
{
    std::cout << "PunchA4, Combo 1 completed " << std::endl;
    comboRow = 0;
    input = 0;
    lastInput = 0;
}

// Combo 2: 1 1 1 1
void KickA1()
{
    std::cout << "KickA1 " << std::endl;
    comboRow++;
}

void KickA2()
{
    std::cout << "KickA2 " << std::endl;
    comboRow++;
}

void KickA3()
{
    std::cout << "KickA3 " << std::endl;
    comboRow++;
}

void KickA4()
{
    std::cout << "KickA4, Combo 2 completed " << std::endl;
    comboRow = 0;
    input = 0;
    lastInput = 0;
}

// Combo 3: 0 0 1 1

// The First two Punch is the same as combo1 
// But The Kick different
void KickB1()
{
    std::cout << "KickB1 " << std::endl;
    comboRow++;
}

void KickB2()
{
    std::cout << "KickB2 Combo 3 completed " << std::endl;
    comboRow = 0;
    input = 0;
    lastInput = 0;
}

int main()
{
    // Jumlah pencetan combo ada 4 dan max tombol ada 2 (0 dan 1), jadi kita buat array dengan panjang 4 x 2 = 8, buat 4 array(berdasar jumlah pencetan combo )
    
    std::vector< std::vector< void (*)() > > arrayOfComboFunc;
    arrayOfComboFunc.reserve( 4 );
    
    void (*Attack)();
    
    std::cout << arrayOfComboFunc.size() << std::endl;
    
    for(int i = 0; i < 4; i++)
    {
        arrayOfComboFunc.emplace_back();
        arrayOfComboFunc[i].reserve( 8 );
    }
    
    std::vector<int> combo1 = { 0, 0, 0, 0 };
    std::vector<int> combo2 = { 1, 1, 1, 1 };
    std::vector<int> combo3 = { 0, 0, 1, 1 };
    
    std::vector<  void (*)() > skillCombo1 = { &PunchA1, &PunchA2, &PunchA3, PunchA4 };
    std::vector<  void (*)() > skillCombo2 = { &KickA1, &KickA2, &KickA3, &KickA4 };
    std::vector<  void (*)() > skillCombo3 = { &PunchA1, &PunchA2, &KickB1, &KickB2 };
     
    
    // Assign all to BreakCombo first
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            arrayOfComboFunc[i].push_back( BreakCombo );
        }
    }
    
        int lastCombo1 = 0;
        int lastCombo2 = 0;
        int lastCombo3 = 0;
    
    for(int i = 0; i < arrayOfComboFunc.size(); i++)
    {
        lastCombo1 += combo1[ i ] ;
        lastCombo2 += combo2[ i ] ;
        lastCombo3 += combo3[ i ] ;
        
        // Combo 1 
        arrayOfComboFunc[i][ lastCombo1 + i] = skillCombo1[i];
        
        // Combo 2, will reassign the same function, PunchA1 and PunchA2
        // But no problem, for simplicity
        arrayOfComboFunc[i][ lastCombo2 + i] = skillCombo2[i];
        
        // Combo 3
        arrayOfComboFunc[i][ lastCombo3 + i] = skillCombo3[i];
    }
    
        std::cout << "Combo 1 : 0 0 0 0 \n";
        std::cout << "Combo 2 : 1 1 1 1 \n";
        std::cout << "Combo 3 : 0 0 1 1 \n";
    
    /// The Loop
    while(true)
    { 
        std::cout << "Input : ( 0 or 1 ) : ";
        std::cin >> input;
        
        //Here we go the Combosss
        arrayOfComboFunc[ comboRow ][ comboRow+input+lastInput ]();
        
        lastInput += input;
    }
    
    return 0;
}
