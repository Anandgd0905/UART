// define typedef
typedef unsigned int uint;
#define LINE_INFO (printf("\n line num = %d", __LINE__) )
#define FUNC_INFO (printf("\n Func name = %s", __func__) )

// Define the register offset addresses
#define	    TX_DATA_REG_OFFSET      			       0x00 //RW 
#define	    RX_DATA_REG_OFFSET 		 		       0x04 //R
#define	    CTRL_REG_1_OFFSET   			       0x08 //RW
#define     CTRL_REG_2_OFFSET   			       0x0C //RW
#define     STATUS_REG_OFFSET   			       0x10 //R
#define     CTRL_REG_3_OFFSET   			       0x14 //RW
#define     UART_HW_IP_BA                                      0x00
//MASK
#define     STAT_REG_TXRDY_MASK                                0x01
#define     STAT_REG_TXRDY_RSHIFT                              0
#define     STAT_REG_RXRDY_MASK                                0x02
#define     STAT_REG_RXRDY_RSHIFT                              1
#define     STAT_REG_PAR_ERR_MASK                              0x04
#define     STAT_REG_PAR_ERR_RSHIFT                            2
#define     STAT_REG_OVERFLOW_MASK                             0x08
#define     STAT_REG_OVERFLOW_RSHIFT                           3
#define     STAT_REG_FRMERR_MASK                               0x10
#define     STAT_REG_FRMERR_RSHIFT                             4



void uart_dummy();
////////////////////////////////////////////////////////////////////////////////////
// Write Function prototypes based on the UART programmer mode

/*
 * This function writes UART transmit data in to the UART Tx data register offset
 * Base_addr is the base address of the UART IP
 * Tx_Data_Reg_Ofst is the address of the register
 * Tx_Data is the data which is to be written in to the register
 *
*/
void Uart_Set_Tx_Data(uint Base_Addr, uint Tx_Data_Reg_Ofst, uint Tx_Data);

/*
 * This function reads UART transmit data from the UART Tx data register offset
 * Base_addr is the base address of the UART IP
 * Tx_Data_Reg_Ofst is the address of the register
*/
// Method 1
uint Uart_Get_Tx_Data(uint Base_Addr, uint Tx_Data_Reg_Ofst);

// Method 2
// uint Uart_Get_Tx_Data(uint Base_Addr, uint Tx_Data_Reg_Ofst);

////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART reciever data in to the UART Rx data register offset
 * Base_addr is the base address of the UART IP
 * Rx_Data_Reg_Ofst is the address of the register
 * Rx_Data is the data which is to be read from the register
 *
*/
uint Uart_Get_Rx_Data(uint Base_Addr, uint Rx_Data_Reg_Ofst);

////////////////////////////////////////////////////////////////////////////////////


/*
 * This function writes UART Ctrl Reg Transmit data in to the UART ctrl_reg1 offset
 * Base_addr is the base address of the UART IP
 * Ctrl_Reg1_Ofst is the address of the Ctrl register
 * Ctrl_reg1_Val is the data which is to be written in to the register
 *
*/

void Uart_Set_Ctrl_Reg1(uint Base_Addr, uint Ctrl_Reg1_Ofst, uint Ctrl_Reg1_Val);

////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART Ctrl reg receive data in to the UART ctrl_reg1 register offset
 * Base_addr is the base address of the UART IP
 * Ctrl_Reg1_Ofst is the address of the register
 *
*/
uint Uart_Get_Ctrl_Reg1(uint Base_Addr, uint Ctrl_Reg1_Ofst);


/*
 * This function writes UART Ctrl Reg2 transmit data in to the UART ctrl_reg1 offset
 * Base_addr is the base address of the UART IP
 * Ctrl_Reg2_Ofst is the address of the register
 * Ctrl_reg2 is the data which is to be written in to the register
 *
*/

void Uart_Set_Ctrl_Reg2(uint Base_Addr, uint Ctrl_Reg2_Ofst, uint Ctrl_Reg2_Val);


////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART Ctrl reg2 reciever data in to the UART ctrl_reg1 register offset
 * Base_addr is the base address of the UART IP
 * Ctrl_Reg2_Ofst is the address of the register
 * 
 *
*/
uint Uart_Get_Ctrl_Reg2(uint Base_Addr, uint Ctrl_Reg2_Ofst);


////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART Status Reg  reciever data in to the UART Status data register offset
 * Base_addr is the base address of the UART IP
 * Status_Reg_Ofst, is the address of the status register of UART IP
 *
*/
uint Uart_Get_Status_Reg(uint Base_Addr, uint Status_Reg_Ofst);

/*
 * This function writes UART Ctrl reg3 transmit data in to the UART ctrl_reg3 offset
 * Base_addr is the base address of the UART IP
 * Ctrl_Reg3_Ofst is the address of the register
 * Ctrl_reg3 is the data which is to be written in to the register
 *
*/

void Uart_Set_Ctrl_Reg3(uint Base_Addr, uint Ctrl_Reg3_Ofst, uint Ctrl_Reg3_Val);


////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART Ctrl Reg recieve data in to the UART ctrl_reg3 register offset
 * Base_addr is the base address of the UART IP
 * Ctrl_Reg3_Ofst is the address of the register
 *
*/
uint Uart_Get_Ctrl_Reg3(uint Base_Addr, uint Ctrl_Reg3_Ofst);


// Control Register 2  Functions
//Bit 8
//This function will Clr the 0th bit of the Ctrl Reg2 Val.
uint Uart_Clr_Ctrl_Reg2_Bit8(uint Base_Addr, uint Ctrl_Reg2_Ofst);
//This function will Set the 0th bit of the Ctrl Reg2 Val.
uint Uart_Set_Ctrl_Reg2_Bit8(uint Base_Addr, uint Ctrl_Reg2_Ofst);
//This Function will read the 0th Bit of the Ctrl Reg2 Val
uint Uart_Get_Ctrl_Reg2_Bit8(uint Base_Addr, uint Ctrl_Reg2_Ofst);


//parity
//This function will Clr the 1th bit of the Ctrl Reg2 Val.
uint Uart_Clr_Ctrl_Reg2_Parity_En(uint Base_Addr, uint Ctrl_Reg2_Ofst);
//This function will Set the 1th bit of the Ctrl Reg2 Val.
uint Uart_Set_Ctrl_Reg2_Parity_En(uint Base_Addr, uint Ctrl_Reg2_Ofst);
//This Function will read the 1th Bit of the Ctrl Reg2 Val
uint Uart_Get_Ctrl_Reg2_Parity_En(uint Base_Addr, uint Ctrl_Reg2_Ofst);


//Even or odd parity
//This function will Clr the 2nd bit of the Ctrl Reg2 Val.
uint Uart_Clr_Ctrl_Reg2_EO_Parity(uint Base_Addr, uint Ctrl_Reg2_Ofst);
//This function will Set the 2nd bit of the Ctrl Reg2 Val.
uint Uart_Set_Ctrl_Reg2_EO_Parity(uint Base_Addr, uint Ctrl_Reg2_Ofst);
//This Function will read the 2nd Bit of the Ctrl Reg2 Val
uint Uart_Get_Ctrl_Reg2_EO_Parity(uint Base_Addr, uint Ctrl_Reg2_Ofst);



// Status Register Functions ….
// Below listed Registers is of 5 bit are.
// It is sub Register parts of Status Reg which included 
// Bit 0----Tx Ready
// Bit 1----Rx Ready
// Bit 2----Parity Error
// Bit 3----Overflow Error
// Bit 4----Frame Error
//Tx Ready
//This Function will read the 0th bit of the Status Reg Val
uint Uart_Get_Stat_Txrdy(uint Stat_Reg_Val);


//Rx Ready
//This Function will read the 1st bit of the Status Reg Val
uint Uart_Get_Stat_Rxrdy(uint Stat_Reg_Val);


//ParErr
//This Function will read the 2nd bit of the Status Reg Val
uint Uart_Get_Stat_ParErr(uint Stat_Reg_Val);


//Overflow
//This Function will read the 3rd bit of the Status Reg Val
uint Uart_Get_Stat_Overflow(uint Stat_Reg_Val);


//Frame Error
//This Function will read the 4th bit of the Status Reg Val
uint Uart_Get_Stat_FrmErr(uint Sat_Reg_Val);



// This function will read upper 5 bits of the 13bit baud value
uint Uart_Get_Ctrl_Reg2_5MSB(uint Ctrl_Reg2_Val);
//This function will write upper 5 bit of the 13 bit value
uint Uart_Set_Ctrl_Reg2_5MSB(uint Ctrl_Reg2_Val);

// Get 13 bit baud value
// This function reads UART Ctrl Reg1 and Reg2 recieve data in to the UART 
// Ctrl_Reg1_Val is the ctrl Reg1 value--5 bit
// Ctrl_Reg2_val is the Ctrl Reg2 value---8 bit
uint Uart_Get_Baud_All_13Bits(uint Ctrl_Reg1_Val, uint Ctrl_Reg2_Val);
//This Function will Write the 13 bit Data to the Baud value.
//Ctrl_Reg1_val is the Reg1 Ctrl register value-- 5 bit
//Ctrl_reg2_val is the reg2 Ctrl register value--8bit
void Uart_Set_Baud_All_13Bits(uint Ctrl_Reg1_Val, uint Ctrl_Reg2_Val, uint Baud_Value);


//This Function will Reads first Five MSB bit from  13 bit baud value .
uint Uart_Get_Baud_5MSB_from_13Bits(uint 13bit_Baud_Val);

///This Function will Reads Last Eight LSB bits From 13 Bit Baud value .
uint Uart_Get_Baud_8LSB_from_13Bits(uint 13bit_Baud_Val);

//Below function will calculate the Baud Value of UART IP.
//Baud_Rate is the input value assigned for calculating the Baud value.
//Clk_Freq is the Freq at which Uart IP is working on.

uint Uart_Calc_Baud_Val(uint Baud_Rate, uint Clk_Freq);

//Below Function will Calculate The Baud Rate Of the Uart IP.
//Baud_Val is the input value assigned for calculating the baud rate
//Clk_Freq is the Freq at which Uart IP is working on.
uint Uart_Calc_Baud_Rate(uint Baud_Val, uint Clk_Freq);

