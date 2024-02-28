#include "/nfs/site/disks/smx_fmm_rtl_2/users/shuklaap/CP/uart/driver/uart_tx_rx.h"
#include <stdio.h>

int main ()
{
    printf("\n UART Testing .... %s \n", __TIME__);
    uart_dummy();
    // call other functions here
    // Test the Txrdy bit field of the UART status register
#if 0    
    uint Txrdy_bit, Stat_Reg;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Txrdy_bit = Uart_Get_Stat_Txrdy(Stat_Reg);
        printf("\nLine %d:Txrdy bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Txrdy_bit, Stat_Reg);
    } 
#endif

#if 0
    uint Rxrdy_bit, Stat_Reg;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Rxrdy_bit = Uart_Get_Stat_Rxrdy(Stat_Reg);
        printf("\nLine %d:Rxrdy bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Rxrdy_bit, Stat_Reg);
    }
#endif

//#if 0
    uint ParErr_bit, Stat_Reg;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        ParErr_bit = Uart_Get_Stat_ParErr(Stat_Reg);
        printf("\nLine %d:ParErr bit is %u with Status Reg Val = 0x%x", __LINE__,ParErr_bit, Stat_Reg);
    }
//#endif
#if 0
    uint Overflow_bit, Stat_Reg;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Overflow_bit = Uart_Get_Stat_Overflow(Stat_Reg);
        printf("\nLine %d:Overflow bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Overflow_bit, Stat_Reg);
    }
#endif
#if 0
    uint  Frmerr_bit, Stat_Reg;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Frmerr_bit = Uart_Get_Stat_FrmErr(Stat_Reg);
        printf("\nLine %d:Frmerr bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Frmerr_bit, Stat_Reg);
    }

#endif


#if 0     
    printf("\n");
    //uint Rxrdy1;
    // 0x0 = 00000000  => 0
    uint Rxrdy = Uart_Get_Stat_Rxrdy(0x02);
    printf("\nRxrdy bit is 0x0%x", Rxrdy);
    return Rxrdy;
    printf("\n");
   
    uint Rxrdy2;
    // 0x10 = 00010000 => 0
    Uart_Get_Stat_Rxrdy(0x10, Rxrdy2);
    printf("\nRxrdy bit is %u", Rxrdy2);
    printf("\n");
    uint Rxrdy3;
    // 0x07 = 00000111  => 1
    Uart_Get_Stat_Rxrdy(0x07, Rxrdy3);
    printf("\nRxrdy bit is %u", Rxrdy3);
    printf("\n");


    //uint ParErr1;
    // 0x0 = 00000000  => 0
    uint ParErr1 = Uart_Get_Stat_ParErr(0x0);
    printf("\nParErr bit is 0x%x", ParErr1);
    return ParErr1;
    printf("\n");
#endif

#if 0

    uint ParErr2;
    // 0x02 = 00000010 => 0
    Uart_Get_Stat_ParErr(0x02, ParErr2);
    printf("\nParErr bit is %u", ParErr2);
    printf("\n");
    uint ParErr3;
    // 0x07 = 00000111  => 1
    Uart_Get_Stat_ParErr(0x07, ParErr3);
    printf("\nParErr bit is %u", ParErr3);
    printf("\n");
    uint Overflow1;
    // 0x0 = 00000000  => 0
    Uart_Get_Stat_Overflow(0x0, Overflow1);
    printf("\nOverflow bit is %u", Overflow1);
    printf("\n");
    uint Overflow2;
    // 0x02 = 00000010 => 0
    Uart_Get_Stat_Overflow(0x02, Overflow2);
    printf("\nOverflow bit is %u", Overflow2);
    printf("\n");
    uint Overflow3;
    // 0x0f = 00001111  => 1
    Uart_Get_Stat_Overflow(0x0f, Overflow3);
    printf("\nOverflow bit is %u", Overflow3);
    printf("\n");
    uint FrmErr1;
    // 0x0 = 00000000  => 0
    Uart_Get_Stat_FrmErr(0x0, FrmErr1);
    printf("\nFrmErr bit is %u", FrmErr1);
    printf("\n");
    uint FrmErr2;
    // 0x02 = 00000010 => 0
    Uart_Get_Stat_FrmErr(0x02, FrmErr2);
    printf("\nFrmErr bit is %u", FrmErr2);
    printf("\n");
    uint FrmErr3;
    // 0x10 = 00010000  => 1
    Uart_Get_Stat_FrmErr(0x10, FrmErr3);
    printf("\nFrmErr bit is %u", FrmErr3);
    printf("\n");

    return 0;

#endif
}
