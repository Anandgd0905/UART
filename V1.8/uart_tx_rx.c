#include <stdio.h>
#include "uart_tx_rx.h"


void uart_dummy()
{
    printf("\n uart dummy\n");
}
/*
Function name is Uart_Get_Status_Reg
Arguments are Base_Address, Stat_Reg_Ofst and Stat_Reg_Val
Base_Address is the based address of the UART IP
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

void Uart_Set_Tx_Data(uint Base_Addr, uint Tx_Data_Reg_Ofst, uint  Tx_Data)
{
    uint *EA;
    EA = Base_Addr + Tx_Data_Reg_Ofst;
    printf("\n Efective Address of UART Tx Data Register = 0x%x \n", EA);
    *EA = Tx_Data;
    printf("\n Value @ EA = 0x%x \n",*EA);
}
//TX_DATA Reg offset READ

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
                             
void Uart_Set_Ctrl_Reg1(uint Base_Addr, uint Ctrl_Reg1_Ofst, uint Ctrl_Reg1_Val)
{
    uint *EA;
    EA = Base_Addr + Ctrl_Reg1_Ofst;
    printf("\n Efective Address of UART CTRL Data Register1 = 0x%x \n", EA);
    *EA = Ctrl_Reg1_Val ;
    printf("\n Value @ EA = 0x%x \n",*EA);
    

}

//CTRL REG1 READ
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
void Uart_Set_Ctrl_Reg2(uint Base_Addr, uint Ctrl_Reg2_Ofst, uint Ctrl_Reg2_Val)
{
    uint *EA;
    EA = Base_Addr + Ctrl_Reg2_Ofst;
    printf("\n Efective Address of UART CTRL Data Register2 = 0x%x \n", EA);
    *EA = Ctrl_Reg2_Val ;
    printf("\n Value @ EA = 0x%x \n",*EA);
}

//CTRL REG2 READ
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
void Uart_Set_Ctrl_Reg3(uint Base_Addr, uint Ctrl_Reg3_Ofst, uint Ctrl_Reg3_Val)
{
    uint *EA;
    EA = Base_Addr + Ctrl_Reg3_Ofst;
    printf("\n Efective Address of UART CTRL Data Register3 = 0x%x \n", EA);
    *EA = Ctrl_Reg3_Val ;
    printf("\n Value @ EA = 0x%x \n",*EA);
}

//CTRL REG3 READ
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
uint Uart_Get_Bit8(uint   Ctrl_reg_2_Val)
{
    uint Bit8;
}
void Uart_Set_Bit8(uint   Ctrl_reg_2_Val, uint Bit8)
{
    
}


//parity
uint Uart_Get_Parity_EnDisBit (uint Ctrl_reg_2_Val)
{
    uint Parity;
}

void Uart_Set_Parity_EnDisBit (uint Ctrl_reg_2_Val, uint Parity)
{
    
}



//Even or odd parity
uint Uart_Get_EO_Parity(uint Ctrl_reg_2_Val )
{
    uint EO_Parity;
}

void Uart_Set_EO_Parity(uint Ctrl_reg_2_Val, uint EO_Parity)
{
    
}



// Buad
uint Uart_Get_Baud_Val_5Bit(uint Ctrl_reg_2_Val)
{
    uint Baud_5Bits;
}

void Uart_Set_Baud_Val_5Bit(uint Ctrl_reg2_Val, uint Baud_5Bits)
{
    
}


// Control Register 3 Functions 
uint Uart_Get_Baud_Val_Fraction(uint Ctrl_reg_3_Val)
{
    uint BaudF;
}

void Uart_Set_Baud_Val_Fraction(uint Ctrl_reg_3_Val, uint BaudF)
{
    ;
}


// Get 13 bit baud value
uint Uart_Get_Baud_All_13Bits(uint Ctrl_reg_1_Val, uint Baud_5Bits)
{
     uint Baud_13Bits;
}

