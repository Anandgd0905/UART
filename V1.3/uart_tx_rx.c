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
void	Uart_Get_Status_Regt(uint Base_Address, uint  Stat_Reg_Ofst, uint Stat_Reg_Val)
{
    uint *EA; // Effective Address
    *EA =  Base_Address + Stat_Reg_Ofst;
    Stat_Reg_Val = *EA;
    printf("\n Status Register value is 0x%x",Stat_Reg_Val );
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


