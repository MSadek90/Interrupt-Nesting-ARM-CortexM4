



#define NVIC_BASE_ADDRESS       0xE000E100



typedef struct 
{

      uint32_t NVIC_ISER[8]; /*Interrupt Set-enable Registers*/
      
      uint32_t RESRVED_1[24]; 
      
      uint32_t NVIC_ICER[8]; /*Interrupt Clear-enable Registers*/
      
      uint32_t RESRVED_2[24];
      
      uint32_t NVIC_ISPR[8]; /*Interrupt Set-pending Registers*/
      
      uint32_t RESRVED_3[24];
      
      uint32_t NVIC_ICPR[8]; /*Interrupt Clear-pending Registers*/
      
      uint32_t RESRVED_4[24];
      
      uint32_t NVIC_IABR[8]; /*Interrupt Active Bit Registers*/
      
      uint32_t RESRVED_5[24];
      
      uint8_t NVIC_IPR[240]; /*Interrupt Priority Registers*/
      
      uint32_t RESRVED_6[644];
      
      uint32_t STIR;         /*Software Trigger Interrupt Register*/

}NVIC_REG_t;


#define NVIC          ((volatile NVIC_REG_t*)NVIC_BASE_ADDRESS)
#define IPR           ((volatile uint8_t*)0xE000E400)
