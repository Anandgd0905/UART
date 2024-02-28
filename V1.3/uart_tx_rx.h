// define typedef
typedef unsigned int uint;

// Define the register offset addresses
#define  TX_DATA_REG_OFFSET  0x00 
#define  RX_DATA_REG_OFFSET  0x04 
#define  CTRL_REG_1_OFFSET   0x08 
#define  CTRL_REG_2_OFFSET   0x0C 
#define  STATUS_REG_OFFSET   0x10 
#define  CTRL_REG_3_OFFSET   0x14 

//MASK
#define     STAT_REG_TXRDY_MASK                                 0x01
#define     STAT_REG_TXRDY_RSHIFT                               0
#define     STAT_REG_RXRDY_MASK                                 0x02
#define     STAT_REG_RXRDY_RSHIFT                               1
#define     STAT_REG_PAR_ERR_MASK                               0x04
#define     STAT_REG_PAR_ERR_RSHIFT                             2
#define     STAT_REG_OVERFLOW_MASK                              0x08
#define     STAT_REG_OVERFLOW_RSHIFT                            3
#define     STAT_REG_FRMERR_MASK                                0x10
#define     STAT_REG_FRMERR_RSHIFT                              4



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
 * Tx_Data is the data which is to be read from te registger
*/
// Method 1
void Uart_Get_Tx_Data(uint Base_Addr, uint Tx_Data_Reg_Ofst, uint Tx_Data);

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
void Uart_Get_Rx_Data(uint Base_Addr, uint Rx_Data_Reg_Ofst, uint Rx_Data);

////////////////////////////////////////////////////////////////////////////////////


/*
 * This function writes UART transmit data in to the UART ctrl_reg1 offset
 * Base_addr is the base address of the UART IP
 * Tx_ctrl_Reg1_Ofst is the address of the register
 * Tx_ctrl_reg1 is the data which is to be written in to the register
 *
*/

void Uart_Set_Ctrl_Reg1(uint Base_Addr, uint Ctrl_Reg1_Ofst, uint Ctrl_Reg1_Val);

////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART reciever data in to the UART ctrl_reg1 register offset
 * Base_addr is the base address of the UART IP
 * Rx_ctrl_Reg1_Ofst is the address of the register
 * Rx_ctrl_reg1 is the data which is to be read from the register
 *
*/
void Uart_Get_Ctrl_reg1(uint Base_Addr, uint Ctrl_Reg1_Ofst, uint Ctrl_Reg1_Val);


/*
 * This function writes UART transmit data in to the UART ctrl_reg1 offset
 * Base_addr is the base address of the UART IP
 * Tx_ctrl_Reg2_Ofst is the address of the register
 * Tx_ctrl_reg2 is the data which is to be written in to the register
 *
*/

void Uart_Set_Ctrl_reg2(uint Base_Addr, uint Tx_Ctrl_Reg2_Ofst, uint Ctrl_Reg2_Val);


////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART reciever data in to the UART ctrl_reg1 register offset
 * Base_addr is the base address of the UART IP
 * Rx_ctrl_Reg2_Ofst is the address of the register
 * Rx_ctrl_reg2 is the data which is to be read from the register
 *
*/
void Uart_Get_Ctrl_Reg2(uint Base_Addr, uint Ctrl_Reg2_Ofst, uint Ctrl_Reg2_Val);


////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART reciever data in to the UART Rx data register offset
 * Base_addr is the base address of the UART IP
 * Status_Reg_Ofst, is the address of the status register of UART IP
 * Stat_Reg_Val is the variable where status is copied/read.
 *
*/
void Uart_Get_Status_Reg(uint Base_Addr, uint Status_Reg_Ofst, uint Stat_Reg_Val);

/*
 * This function writes UART transmit data in to the UART ctrl_reg1 offset
 * Base_addr is the base address of the UART IP
 * Tx_ctrl_Reg3_Ofst is the address of the register
 * Tx_ctrl_reg3 is the data which is to be written in to the register
 *
*/

void Uart_Set_Ctrl_Reg3(uint Base_Addr, uint Ctrl_Reg3_Ofst, uint Ctrl_Reg3_Val);


////////////////////////////////////////////////////////////////////////////////////
/*
 * This function reads UART reciever data in to the UART ctrl_reg1 register offset
 * Base_addr is the base address of the UART IP
 * Rx_ctrl_Reg3_Ofst is the address of the register
 * Rx_ctrl_reg3 is the data which is to be read from the register
 *
*/
void Uart_Get_Ctrl_Reg3(uint Base_Addr, uint Ctrl_Reg3_Ofst, uint Ctrl_Reg3_Val);


// Control Register 2  Functions
//Bit 8
void Uart_Get_Bit8(uint   Ctrl_reg_2_Val, uint Bit8);
void Uart_Set_Bit8(uint   Ctrl_reg_2_Val, uint Bit8);


//parity
void Uart_Get_Parity_EnDisBit (uint Ctrl_reg_2_Val, uint Parity);
void Uart_Set_Parity_EnDisBit (uint Ctrl_reg_2_Val, uint Parity);


//Even or odd parity
void Uart_Get_EO_Parity(uint Ctrl_reg_2_Val, uint EO_Parity);
void Uart_Set_EO_Parity(uint Ctrl_reg_2_Val, uint EO_Parity);


// Buad
void Uart_Get_Baud_Val_5Bit(uint	Ctrl_reg_2_Val, uint Baud_5Bits);
void Uart_Set_Baud_Val_5Bit(uint	Ctrl_reg_2_Val, uint Baud_5Bits);


// Control Register 3 Functions ?
void Uart_Get_Baud_Val_Fraction(uint	Ctrl_reg_3_Val, uint BaudF);
void Uart_Set_Baud_Val_Fraction(uint	Ctrl_reg_3_Val, uint BaudF);


// Status Register Functions ….
//Tx Ready
uint Uart_Get_Stat_Txrdy(uint Stat_Reg_Val);


//Rx Ready
uint Uart_Get_Stat_Rxrdy(uint Stat_Reg_Val);


//ParErr
uint Uart_Get_Stat_ParErr(uint Stat_Reg_Val);


//Overflow
uint Uart_Get_Stat_Overflow(uint Stat_Reg_Val);


//Frame Error
uint Uart_Get_Stat_FrmErr(uint Sat_Reg_Val);


// Get 13 bit baud value
void Uart_Get_Baud_All_13Bits(uint	Ctrl_reg_1_Val, uint Baud_5Bits, uint Baud_13Bits);

