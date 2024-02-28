#include "/nfs/site/disks/smx_fmm_rtl_2/users/shuklaap/CP/uart/Driver/uart_tx_rx.h"
#include <stdio.h>
uint UartHw_ip[24];
void UartHw_Ip();

int main ()
{
    printf("\n UART Testing .... %s \n", __TIME__);
    uart_dummy();
    
#if 0
    // call other functions here
    // Test the Txrdy bit field of the UART status register
    uint Stat_Reg; 

    uint Txrdy_bit;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Txrdy_bit = Uart_Get_Stat_Txrdy(Stat_Reg);
        printf("\nLine %d:Txrdy bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Txrdy_bit, Stat_Reg);
    } 



    uint Rxrdy_bit;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Rxrdy_bit = Uart_Get_Stat_Rxrdy(Stat_Reg);
        printf("\nLine %d:Rxrdy bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Rxrdy_bit, Stat_Reg);
    }



    uint ParErr_bit;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        ParErr_bit = Uart_Get_Stat_ParErr(Stat_Reg);
        printf("\nLine %d:ParErr bit is %u with Status Reg Val = 0x%x", __LINE__,ParErr_bit, Stat_Reg);
    }


    uint Overflow_bit;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Overflow_bit = Uart_Get_Stat_Overflow(Stat_Reg);
        printf("\nLine %d:Overflow bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Overflow_bit, Stat_Reg);
    }


    uint  Frmerr_bit;
    for(Stat_Reg = 0; Stat_Reg <= 0xFF; Stat_Reg++)
    {
        Frmerr_bit = Uart_Get_Stat_FrmErr(Stat_Reg);
        printf("\nLine %d:Frmerr bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Frmerr_bit, Stat_Reg);
    }

#endif


    //--------------------------------------
    //TX_DATA_REG --> RW
    //--------------------------------------
    UartHw_Ip();
    uint *BA;
    BA = &UartHw_ip[UART_HW_IP_BA]; //The second Reg address is the base addres
    printf("\n BA = 0x%x, val @ BA = 0x%x \n",BA,*BA);
    
    
    Uart_Set_Tx_Data(BA, TX_DATA_REG_OFFSET, 0xAC);	
    uint Tx_Data = 0;
    Tx_Data = Uart_Get_Tx_Data(BA,TX_DATA_REG_OFFSET);
    printf("\n Tx Data = 0x%x \n",Tx_Data );
    
    
    
    //--------------------------------------
    //RX_DATA_REG --> R
    //--------------------------------------
    
    
    uint Rx_Data = 0;
    Rx_Data = Uart_Get_Rx_Data(BA,RX_DATA_REG_OFFSET);
    printf("\n Rx Data = 0x%x \n",Rx_Data );
    
    //--------------------------------------
    //CTRL_DATA_REG1 --> RW
    //--------------------------------------
    Uart_Set_Ctrl_Reg1(BA, CTRL_REG_1_OFFSET , 0xD6);	 //To achieve a baud rate of 9600 on a system running at 33MThz, we need to prog ctrl reg value as 0xD6
    uint Ctrl_Reg1_Val = 0;
    Ctrl_Reg1_Val = Uart_Get_Ctrl_Reg1(BA,CTRL_REG_1_OFFSET);
    printf("\n CTRL Data REG1 = 0x%x \n", Ctrl_Reg1_Val);
    
    
    //--------------------------------------
    //CTRL_DATA_REG2 --> RW
    //--------------------------------------
    //
    // Set the bit8, parity,  odd/even parity and upper 5 bits oif the Baud value 
    Uart_Set_Ctrl_Reg2(BA, CTRL_REG_2_OFFSET, 0x08);	
    
    uint Ctrl_Reg2_Val = 0;
    // read the ctrl reg2
    Ctrl_Reg2_Val = Uart_Get_Ctrl_Reg2(BA,CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 = 0x%x \n", Ctrl_Reg2_Val);


    // read Bit8
    uint Ctrl_Reg2_Bit8_Val=0;
    Ctrl_Reg2_Bit8_Val = Uart_Get_Ctrl_Reg2_Bit8(BA, CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 Bit8= %d \n", Ctrl_Reg2_Bit8_Val);

   
    // set Bit 8
    Uart_Set_Ctrl_Reg2_Bit8(BA, CTRL_REG_2_OFFSET);
    
    // again read Bit 8
    Ctrl_Reg2_Bit8_Val = Uart_Get_Ctrl_Reg2_Bit8(BA, CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 Bit8= %d \n", Ctrl_Reg2_Bit8_Val);
  
    // clear bit 8
    Uart_Clr_Ctrl_Reg2_Bit8(BA, CTRL_REG_2_OFFSET);
    
    // again read Bit 8
    Ctrl_Reg2_Bit8_Val = Uart_Get_Ctrl_Reg2_Bit8(BA, CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 Bit8= %d \n", Ctrl_Reg2_Bit8_Val);
    
    

    //set Parity En
    Uart_Set_Ctrl_Reg2_Parity_En(BA, CTRL_REG_2_OFFSET);
    //read Parity En
    uint Ctrl_Reg2_Parity_En_Val=0;
    Ctrl_Reg2_Parity_En_Val = Uart_Get_Ctrl_Reg2_Parity_En(BA, CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 = 0x%x \n", Ctrl_Reg2_Parity_En_Val);
    //clear Parity En
    Uart_Clr_Ctrl_Reg2_Parity_En(BA, CTRL_REG_2_OFFSET);
    Ctrl_Reg2_Parity_En_Val = Uart_Get_Ctrl_Reg2_Parity_En(BA, CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 = 0x%x \n", Ctrl_Reg2_Parity_En_Val);
    
    //set EO Parity
    Uart_Set_Ctrl_Reg2_EO_Parity(BA, CTRL_REG_2_OFFSET);
    //Read EO Parity
    uint Ctrl_Reg2_EO_Parity_Val=0;
    Ctrl_Reg2_EO_Parity_Val = Uart_Get_Ctrl_Reg2_EO_Parity(BA, CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 = 0x%x \n", Ctrl_Reg2_EO_Parity_Val);
    //Clr EO parity 
    Uart_Clr_Ctrl_Reg2_EO_Parity(BA, CTRL_REG_2_OFFSET);
    Ctrl_Reg2_EO_Parity_Val = Uart_Get_Ctrl_Reg2_EO_Parity(BA, CTRL_REG_2_OFFSET);
    printf("\n CTRL Data REG2 = 0x%x \n", Ctrl_Reg2_EO_Parity_Val);




    //--------------------------------------
    //CTRL_DATA_REG3 --> RW
    //--------------------------------------
    //
    
    Uart_Set_Ctrl_Reg3(BA, CTRL_REG_3_OFFSET, 0x00);	
    uint Ctrl_Reg3_Val = 0;
    Ctrl_Reg3_Val = Uart_Get_Ctrl_Reg3(BA,CTRL_REG_3_OFFSET);
    printf("\n CTRL Data REG3 = 0x%x \n", Ctrl_Reg3_Val);



    
    //--------------------------------------
    //STATUS_REG --> R
    //--------------------------------------
    //
    
    uint Stat_Reg_Val  = 0;
    Stat_Reg_Val = Uart_Get_Status_Regt(BA,STATUS_REG_OFFSET);
    //printf("ba =", &UartHw_ip[0x04]);
    printf("\n Stat_Reg_Val = 0x%x \n", Stat_Reg_Val);

    uint Txrdy_bit;
    Txrdy_bit = Uart_Get_Stat_Txrdy(Stat_Reg_Val);
    printf("\nLine %d:Txrdy bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Txrdy_bit, Stat_Reg_Val);


    uint Rxrdy_bit;
    Rxrdy_bit = Uart_Get_Stat_Rxrdy(Stat_Reg_Val);
    printf("\nLine %d:Rxrdy bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Rxrdy_bit, Stat_Reg_Val);


    uint ParErr_bit;
    ParErr_bit = Uart_Get_Stat_ParErr(Stat_Reg_Val);
    printf("\nLine %d:ParErr bit is %u with Status Reg Val = 0x%x", __LINE__,ParErr_bit, Stat_Reg_Val);

    uint Overflow_bit;
    Overflow_bit = Uart_Get_Stat_Overflow(Stat_Reg_Val);
    printf("\nLine %d:Overflow bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Overflow_bit, Stat_Reg_Val);

    uint  Frmerr_bit;
    Frmerr_bit = Uart_Get_Stat_FrmErr(Stat_Reg_Val);
    printf("\nLine %d:Frmerr bit is 0x%x with Status Reg Val = 0x%x", __LINE__,Frmerr_bit, Stat_Reg_Val);
 

}

void UartHw_Ip()
{
UartHw_ip[0x00] = 0x00; //0x00;  //Uart TX DATA REG
UartHw_ip[0x01] = 0x00;  
UartHw_ip[0x02] = 0x00;  
UartHw_ip[0x03] = 0x00;  
UartHw_ip[0x04] = 0x01;  
UartHw_ip[0x05] = 0x00;
}
