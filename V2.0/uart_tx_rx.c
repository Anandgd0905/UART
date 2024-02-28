#include <stdio.h>
#include "uart_tx_rx.h"


void uart_dummy()
{
    printf("\n uart dummy\n");
}
/*
Function name is Uart_Get_Status_Reg
Arguments are Base_Address, Stat_Reg_Ofst and Stat_Reg_Val
Base_Address is the base address of the UART IP
Stat_Reg_Ofst is the offset address of the status register of the UART IP
Stat_Reg_Val is the variable into which the status register value is copied/ read.
*/
uint Uart_Get_Status_Regt(uint Base_Address, uint  Stat_Reg_Ofst)
{
    uint  Stat_Reg_Val, *EA; // Effective Address
    EA =  Base_Address + Stat_Reg_Ofst;
    printf("\n Efective Address of UART status Register = 0x%x \n", EA);
    Stat_Reg_Val = *EA;
    printf("\n Status Register value is 0x%x",Stat_Reg_Val);
    return Stat_Reg_Val;
}     

/*
Function name is Uart_Get_Stat_Txrdy and Reads the 0th bit of the Status Register value.
Arguments is Stat_Reg_Val
Stat_Reg_Val is the variable into which the status register value is copied/ read.
*/
uint Uart_Get_Stat_Txrdy(uint Stat_Reg_Val)
{
    uint Txrdy = (Stat_Reg_Val & STAT_REG_TXRDY_MASK) >> STAT_REG_TXRDY_RSHIFT;
    if(Txrdy  == 0)
        printf("\nFunc: %s Line: %d: Txrdy is not Set",__func__,__LINE__);
    else
        printf("\nFunc: %s Line: %d: Txrdy is Set",__func__,__LINE__);
    return Txrdy;

/*
0xff in this 0th bit is set or not ?
= 0xff & 0x01
= (11111111) &(00000001)
= (00000001)
0th bit is 1


0x4, 0th bit ?
0x4 & 0x01
00000100 & 00000001
=00000000
Oth bit is 0


*/
}
// frame err, par err, overflow err, rxrdy

//Rx Ready
/*
Function name is Uart_Get_Stat_Rxrdy and Reads the 1th bit of the Status Register value.
Arguments is Stat_Reg_Val
Stat_Reg_Val is the variable into which the status register value is copied/ read.
*/

uint Uart_Get_Stat_Rxrdy(uint Stat_Reg_Val)
{
    uint Rxrdy = (Stat_Reg_Val & STAT_REG_RXRDY_MASK) >> STAT_REG_RXRDY_RSHIFT ;
    if(Rxrdy  == 0)
        printf("\nFunc: %s Line: %d: Rxrdy is not Set",__func__,__LINE__);
    else
        printf("\nFunc: %s Line: %d: Rxrdy is Set",__func__,__LINE__);
    return Rxrdy;
}

//ParErr
/*
Function name is Uart_Get_Stat_ParErr and Reads the 2nd bit of the Status Register value.
Arguments is Stat_Reg_Val
Stat_Reg_Val is the variable into which the status register value is copied/ read.
*/

uint Uart_Get_Stat_ParErr(uint Stat_Reg_Val)
{
    //uint Parity;
    //Parity ^= Stat_Reg_Val;  // donot calculate parity , it is not needed, we need to see the status and inform.
    uint Par_Err = (Stat_Reg_Val & STAT_REG_PAR_ERR_MASK) >> STAT_REG_PAR_ERR_RSHIFT;
    if(Par_Err  == 0)
        printf("\nFunc: %s Line: %d: Par_Err is not Set : %u",__func__,__LINE__,Par_Err);
    else
        printf("\nFunc: %s Line: %d: Par_Err is Set: %u",__func__,__LINE__, Par_Err);
    return Par_Err;

}


//Overflow
/*
Function name is Uart_Get_Stat_Overflow and Reads the 3rd bit of the Status Register value.
Arguments is Stat_Reg_Val
Stat_Reg_Val is the variable into which the status register value is copied/ read.
*/

uint Uart_Get_Stat_Overflow(uint Stat_Reg_Val)
{
//0x08
   uint Overflow = (Stat_Reg_Val & STAT_REG_OVERFLOW_MASK) >> STAT_REG_OVERFLOW_RSHIFT;
    if(Overflow  == 0)
        printf("\nFunc: %s Line: %d: Overflow is not Set",__func__,__LINE__);
    else
        printf("\nFunc: %s Line: %d: Overflow is Set",__func__,__LINE__);
    return Overflow;
}


//Frame Error
/*
Function name is Uart_Get_Stat_FrmErr and Reads the 4th bit of the Status Register value.
Arguments is Stat_Reg_Val
Stat_Reg_Val is the variable into which the status register value is copied/ read.
*/

   uint Uart_Get_Stat_FrmErr(uint Sat_Reg_Val)
{
    //unit frame;
    //Frame ^ Sat_Reg_Val
    uint Frmerr = (Sat_Reg_Val & STAT_REG_FRMERR_MASK) >> STAT_REG_FRMERR_RSHIFT;
    if(Frmerr  == 0)
        printf("\nFunc: %s Line: %d: Frmerr is not Set i.e. Data received is correct",__func__,__LINE__);
    else
        printf("\nFunc: %s Line: %d: Frmerr is Set i.e. Data received in not correct",__func__,__LINE__);
    return Frmerr;

}


//TX_DATA Reg offset WRITE
/*
Function name is Uart_Set_Tx_data
Arguments are Base_Address, Tx_Data_Reg_Ofst and Tx_Data
Base_Address is the base address of the UART IP
Tx_Data_Reg_Ofst is the offset address of the Tx register of the UART IP
Tx_Data is the variable into which the Tx register value is to be written.
*/
void Uart_Set_Tx_Data(uint Base_Addr, uint Tx_Data_Reg_Ofst, uint  Tx_Data)
{
    uint *EA;
    EA = Base_Addr + Tx_Data_Reg_Ofst;
    printf("\n Efective Address of UART Tx Data Register = 0x%x \n", EA);
    *EA = Tx_Data;
    printf("\n Value @ EA = 0x%x \n",*EA);
}
//TX_DATA Reg offset READ
/*
Function name is Uart_Get_Tx_data
Arguments are Base_Address, Tx_Data_Reg_Ofst, Tx_Data
Base_Address is the base address of the UART IP
Tx_Data_Reg_Ofst is the offset address of the Tx register of the UART IP
Tx_Data is the variable into which the Tx register value is copied/read.
*/


uint Uart_Get_Tx_Data(uint Base_Addr, uint Tx_Data_Reg_Ofst)
{
    uint Tx_Data, *EA;
    EA = Base_Addr + Tx_Data_Reg_Ofst;
    printf("\n Efective Address of UART Tx Data Register = 0x%x \n", EA);
    Tx_Data = *EA;
    printf("\n Value @ EA = 0x%x \n",Tx_Data);
    return Tx_Data;
}



//RX_DATA Reg offset READ
/*
Function name is Uart_Get_Rx_data
Arguments are Base_Address, Rx_Data_Reg_Ofst, Rx_Data
Base_Address is the base address of the UART IP
Rx_Data_Reg_Ofst is the offset address of the Rx register of the UART IP
Rx_Data is the variable into which the Rx register value is copied/read.
*/
uint Uart_Get_Rx_Data(uint Base_Addr, uint Rx_Data_Reg_Ofst)
{
    uint Rx_Data, *EA;
    EA = Base_Addr + (Rx_Data_Reg_Ofst);
    printf("\n Efective Address of UART Rx Data Register = 0x%x \n", EA);
    Rx_Data = *EA;
    printf("\n Value @ EA = 0x%x \n",Rx_Data);
    return Rx_Data;
}

//CTRL REG1 WRITE
/*
Function name is Uart_Set_Ctrl_Reg1
Arguments are Base_Address, Ctrl_Reg1_Ofst and Ctrl_Reg1_Val
Base_Address is the base address of the UART IP
Ctrl_Reg1_Ofst is the offset address of the Ctrl register1 of the UART IP
Ctrl_Reg1_Val is the variable into which the Ctrl register1 value is to be written.
*/                
void Uart_Set_Ctrl_Reg1(uint Base_Addr, uint Ctrl_Reg1_Ofst, uint Ctrl_Reg1_Val)
{
    uint *EA;
    EA = Base_Addr + Ctrl_Reg1_Ofst;
    printf("\n Efective Address of UART CTRL Data Register1 = 0x%x \n", EA);
    *EA = Ctrl_Reg1_Val ;
    printf("\n Value @ EA = 0x%x \n",*EA);
    

}

//CTRL REG1 READ
/*
Function name is Uart_Get_Ctrl_Reg1
Arguments are Base_Address, Ctrl_Reg1_Ofst and Ctrl_Reg1_Val
Base_Address is the base address of the UART IP
Ctrl_Reg1_Ofst is the offset address of the Ctrl register1 of the UART IP
Ctrl_Reg1_Val is the variable into which the Ctrl register1 value is copied/read.
*/  
uint Uart_Get_Ctrl_Reg1(uint Base_Addr, uint Ctrl_Reg1_Ofst)
{
    uint Ctrl_Reg1_Val, *EA;
    EA = Base_Addr + Ctrl_Reg1_Ofst;
    printf("\n Efective Address of UART CTRL Data Register1 = 0x%x \n", EA);
    Ctrl_Reg1_Val = *EA;
    printf("\n Value @ EA = 0x%x \n",Ctrl_Reg1_Val);
    return Ctrl_Reg1_Val;
}

//CTRL REG2 WRITE
/*
Function name is Uart_Set_Ctrl_Reg2
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctr2_Reg1_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg1_Val is the variable into which the Ctrl register2 value is to be written.
*/
void Uart_Set_Ctrl_Reg2(uint Base_Addr, uint Ctrl_Reg2_Ofst, uint Ctrl_Reg2_Val)
{
    uint *EA;
    EA = Base_Addr + Ctrl_Reg2_Ofst;
    printf("\n Efective Address of UART CTRL Data Register2 = 0x%x \n", EA);
    *EA = Ctrl_Reg2_Val ;
    printf("\n Value @ EA = 0x%x \n",*EA);
}

//CTRL REG2 READ
/*
Function name is Uart_Get_Ctrl_Reg2
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is copied/read.
*/ 
uint Uart_Get_Ctrl_Reg2(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val, *EA;
    EA = Base_Addr + Ctrl_Reg2_Ofst;
    printf("\n Efective Address of UART CTRL Data Register2 = 0x%x \n", EA);
    Ctrl_Reg2_Val = *EA;
    printf("\n Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    return Ctrl_Reg2_Val;
}

//CTRL REG3 WRITE
/*
Function name is Uart_Set_Ctrl_Reg3
Arguments are Base_Address, Ctrl_Reg3_Ofst and Ctrl_Reg3_Val
Base_Address is the base address of the UART IP
Ctrl_Reg3_Ofst is the offset address of the Ctrl register3 of the UART IP
Ctrl_Reg3_Val is the variable into which the Ctrl register3 value is to be written.
*/
void Uart_Set_Ctrl_Reg3(uint Base_Addr, uint Ctrl_Reg3_Ofst, uint Ctrl_Reg3_Val)
{
    uint *EA;
    EA = Base_Addr + Ctrl_Reg3_Ofst;
    printf("\n Efective Address of UART CTRL Data Register3 = 0x%x \n", EA);
    *EA = Ctrl_Reg3_Val ;
    printf("\n Value @ EA = 0x%x \n",*EA);
}

//CTRL REG3 READ
/*
Function name is Uart_Get_Ctrl_Reg3
Arguments are Base_Address, Ctrl_Reg3_Ofst and Ctrl_Reg3_Val
Base_Address is the base address of the UART IP
Ctrl_Reg3_Ofst is the offset address of the Ctrl register3 of the UART IP
Ctrl_Reg3_Val is the variable into which the Ctrl register3 value is copied/read.
*/ 
uint Uart_Get_Ctrl_Reg3(uint Base_Addr, uint Ctrl_Reg3_Ofst)
{
    uint Ctrl_Reg3_Val, *EA;
    EA = Base_Addr + Ctrl_Reg3_Ofst;
    printf("\n Efective Address of UART CTRL Data Register3 = 0x%x \n", EA);
    Ctrl_Reg3_Val = *EA;
    printf("\n Value @ EA = 0x%x \n",Ctrl_Reg3_Val);
    return Ctrl_Reg3_Val;
}



// Control Register 2  Functions
//Bit 8
/*
Function name is Uart_Clr_Ctrl_Reg2_Bit8
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil Clr the 0th bit for the Ctrl Reg2 Val.
*/
uint Uart_Clr_Ctrl_Reg2_Bit8(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n Clr Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Ctrl_Reg2_Val = Ctrl_Reg2_Val & 0xFE;
    printf("\n Clr Updated Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Uart_Set_Ctrl_Reg2(Base_Addr, CTRL_REG_2_OFFSET, Ctrl_Reg2_Val);
}

/*
Function name is Uart_Set_Ctrl_Reg2_Bit8
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil Set the 0th bit for the Ctrl Reg2 Val.
*/
uint Uart_Set_Ctrl_Reg2_Bit8(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n Driver: Ctrl reg 2 val before set bit 8= 0x%x \n",Ctrl_Reg2_Val);
    Ctrl_Reg2_Val = Ctrl_Reg2_Val | 0x01;
    printf("\n Driver: Ctrl reg 2 val after set bit8= 0x%x \n",Ctrl_Reg2_Val);
    Uart_Set_Ctrl_Reg2(Base_Addr, CTRL_REG_2_OFFSET, Ctrl_Reg2_Val);
}

/*
Function name is Uart_Get_Ctrl_Reg2_Bit8
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil read the 0th bit for the Ctrl Reg2 Val and reports the received dta is of 7 bit(0th bit is set to 0) or 8 bit(0th bit is set to 1).
*/
uint Uart_Get_Ctrl_Reg2_Bit8(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    //printf("\n Driver: Ctrl Reg2 Val = 0x%x \n",Ctrl_Reg2_Val);
    uint Bit8 = (Ctrl_Reg2_Val & 0x01) >> 0;
    if(Bit8  == 0)
        printf("\nFunc: %s Line: %d: Bit8 is not Set",__func__,__LINE__);
    else
        printf("\nFunc: %s Line: %d: Bit8 is Set",__func__,__LINE__);
    return Bit8;
    
}


//parity
/*
Function name is Uart_Clr_Ctrl_Reg2_parity_En
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil Clr the 1st bit for the Ctrl Reg2 Val.
*/

uint Uart_Clr_Ctrl_Reg2_Parity_En(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n Clr Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Ctrl_Reg2_Val = Ctrl_Reg2_Val & 0xFD;
    printf("\n Clr updated Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Uart_Set_Ctrl_Reg2(Base_Addr, CTRL_REG_2_OFFSET, Ctrl_Reg2_Val);
}

/*
Function name is Uart_Set_Ctrl_Reg2_parity_En
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil Set the 1st bit for the Ctrl Reg2 Val.
*/
uint Uart_Set_Ctrl_Reg2_Parity_En(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n Set Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Ctrl_Reg2_Val = Ctrl_Reg2_Val | 0x02;
    printf("\n Set updated  Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Uart_Set_Ctrl_Reg2(Base_Addr, CTRL_REG_2_OFFSET, Ctrl_Reg2_Val);
}

/*
Function name is Uart_Get_Ctrl_Reg2_parity_En
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil read the 1st bit for the Ctrl Reg2 Val and reports if Parity is Enable(1st bit is set to 1(odd parity)) or Not(1st bit is set to 0(even parity)).
*/

uint Uart_Get_Ctrl_Reg2_Parity_En (uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n Parity read Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    uint Parity_En = (Ctrl_Reg2_Val & 0x02) >> 1;
    if(Parity_En  == 0)
        printf("\nFunc: %s Line: %d: Parity_En is not Set",__func__,__LINE__);
    else
        printf("\nFunc: %s Line: %d: Parity_En is Set",__func__,__LINE__);
    return Parity_En;
}




//Even or odd parity
/*
Function name is Uart_Clr_Ctrl_Reg2_EO_Parity
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil Clr the 2nd bit for the Ctrl Reg2 Val.
*/
uint Uart_Clr_Ctrl_Reg2_EO_Parity(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n Clr Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Ctrl_Reg2_Val = Ctrl_Reg2_Val & 0xFC;
    printf("\n Clr updated Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Uart_Set_Ctrl_Reg2(Base_Addr, CTRL_REG_2_OFFSET, Ctrl_Reg2_Val);
}

/*
Function name is Uart_Clr_Ctrl_Reg2_EO_Parity
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil Set the 2nd bit for the Ctrl Reg2 Val.
*/
uint Uart_Set_Ctrl_Reg2_EO_Parity(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n Set Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Ctrl_Reg2_Val = Ctrl_Reg2_Val | 0x04;
    printf("\n Set updated Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    Uart_Set_Ctrl_Reg2(Base_Addr, CTRL_REG_2_OFFSET, Ctrl_Reg2_Val);
}

/*
Function name is Uart_Get_Ctrl_Reg2_parity_En
Arguments are Base_Address, Ctrl_Reg2_Ofst and Ctrl_Reg2_Val
Base_Address is the base address of the UART IP
Ctrl_Reg2_Ofst is the offset address of the Ctrl register2 of the UART IP
Ctrl_Reg2_Val is the variable into which the Ctrl register2 value is to be written.
This function wil read the 2nd bit for the Ctrl Reg2 Val and reports if Parity is Odd(1st bit is set to 1(odd parity)) or Even(1st bit is set to 0(even parity)).
*/
uint Uart_Get_Ctrl_Reg2_EO_Parity(uint Base_Addr, uint Ctrl_Reg2_Ofst)
{
    uint Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(Base_Addr,CTRL_REG_2_OFFSET);
    printf("\n EO read Value @ EA = 0x%x \n",Ctrl_Reg2_Val);
    uint EO_Parity= (Ctrl_Reg2_Val & 0x04) >> 2;
    if(EO_Parity  == 0)
        printf("\nFunc: %s Line: %d: EO_Parity is not Set",__func__,__LINE__);
    else
        printf("\nFunc: %s Line: %d: EO_Parity is Set",__func__,__LINE__);
    return EO_Parity;

}




// Get upper 5 bits of the 13bit baud value
// Function Name is Uart_Get_Ctrl_Reg2_5MSB
// Argument is Ctrl_Reg2_Val
// It will read the first 5 MSB from Ctrl_Reg2_Val
uint Uart_Get_Ctrl_Reg2_5MSB(uint Ctrl_Reg2_Val)
{
    Ctrl_Reg2_Val= Ctrl_Reg2_Val | 0xF8;

}
// Function Name is Uart_Set_Ctrl_Reg2_5MSB
// Argument is Ctrl_Reg2_Val
// It will write the first 5 MSB to Ctrl_Reg2_Val
uint Uart_Set_Ctrl_Reg2_5MSB(uint Ctrl_Reg2_Val)
{
   Ctrl_Reg2_Val = Ctrl_Reg2_Val >> 3;
}

// Get 13 bit baud value
// function name is Uart_Get_Baud_All_13Bits
// Arguments are Ctrl_Reg1_Val, Ctrl_Reg2_Val
// This function will read the vale of ctrl reg 1 and 2 value.
uint Uart_Get_Baud_All_13Bits(uint Ctrl_Reg1_Val, uint Ctrl_Reg2_Val)
{
    uint Baud_all_13bits = Ctrl_reg1_val | Ctrl_Reg2_Val;
}

// function name is Uart_Set_Baud_All_13Bits
// Arguments are Ctrl_Reg1_Val, Ctrl_Reg2_Val, baud value
// This function will Write the Ctrl reg1 and 2 data to baud value variable.
void Uart_Set_Baud_All_13Bits(uint Ctrl_Reg1_Val, uint Ctrl_Reg2_Val, uint Baud_Value)
{
    Baud_Value = Ctrl_Reg1_Val | Ctrl_Reg1_Val; 
}

// function name is Uart_Set_Baud_All_13Bits
// Arguments are 13bit_baud_val
// This function will Read the fisrt 5 MSB of 13bit baud value.
uint Uart_Get_Baud_5MSB_from_13Bits(uint 13bit_Baud_Val)
{
    13bit_Baud_val = 13bit_Baud_Val >> 8
}


// function name is Uart_Set_Baud_All_13Bits.
// Arguments are 13bit_Baud_Val.
// This function will Read the last 8 bits of 13 bit baud value.
uint Uart_Get_Baud_8LSB_from_13Bits(uint 13bit_Baud_Val)
{
   13bit_Baud_Val = 13bit_Baud_Val | 0x1f;
}


// function name is Uart_Set_Baud_All_13Bits
// Arguments are Baud_Rate, Clk_Freq
// This function will Calculate the Baud value of the uart IP.
uint Uart_Calc_Baud_Val(uint Baud_Rate, uint Clk_Freq)
{
    uint Baud_val = (Clk_Freq/(16*Baud_Rat))-1;
    printf("Baud_Val is %s", Baud_Val);
}

// function name is Uart_Set_Baud_All_13Bits
// Arguments are Baud_Val, Clk_Freq.
// This function will Calculate the Baud rate of the uart IP.

uint Uart_Calc_Baud_Rate(uint Baud_Val, uint Clk_Freq)
{
    Baud_Rate = Clk_Freq/((Baud_Val+1)*16);
    printf("Baud_Rate is %s", Baud_Rate);
}

