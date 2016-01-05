#ifndef C5_H
#define C5_H

//FPGA rgister Address Map
#define HARDWARE_VERSION				(0x00000000/sizeof(int))
#define FAN_SPEED						(0x00000004/sizeof(int))
#define HASH_ON_PLUG					(0x00000008/sizeof(int))
#define BUFFER_SPACE					(0x0000000c/sizeof(int))
#define RETURN_NONCE					(0x00000010/sizeof(int))
#define NONCE_NUMBER_IN_FIFO			(0x00000018/sizeof(int))
#define NONCE_FIFO_INTERRUPT			(0x0000001c/sizeof(int))
#define TEMPERATURE_0_3					(0x00000020/sizeof(int))
#define TEMPERATURE_4_7					(0x00000024/sizeof(int))
#define TEMPERATURE_8_11				(0x00000028/sizeof(int))
#define TEMPERATURE_12_15				(0x0000002c/sizeof(int))
#define TW_WRITE_COMMAND				(0x00000040/sizeof(int))
#define QN_WRITE_DATA_COMMAND			(0x00000080/sizeof(int))
#define FAN_CONTROL						(0x00000084/sizeof(int))
#define TIME_OUT_CONTROL				(0x00000088/sizeof(int))
#define TICKET_MASK_FPGA				(0x0000008c/sizeof(int))
#define HASH_COUNTING_NUMBER_FPGA		(0x00000090/sizeof(int))
#define SNO								(0x00000094/sizeof(int))
#define BC_WRITE_COMMAND				(0x000000c0/sizeof(int))
#define BC_COMMAND_BUFFER				(0x000000c4/sizeof(int))
#define DHASH_ACC_CONTROL				(0x00000100/sizeof(int))
#define COINBASE_AND_NONCE2_LENGTH		(0x00000104/sizeof(int))
#define WORK_NONCE_2					(0x00000108/sizeof(int))
#define NONCE2_AND_JOBID_STORE_ADDRESS	(0x00000110/sizeof(int))
#define MERKLE_BIN_NUMBER				(0x00000114/sizeof(int))
#define JOB_START_ADDRESS				(0x00000118/sizeof(int))
#define JOB_LENGTH						(0x0000011c/sizeof(int))
#define JOB_DATA_READY					(0x00000120/sizeof(int))
#define JOB_ID							(0x00000124/sizeof(int))
#define BLOCK_HEADER_VERSION			(0x00000130/sizeof(int))
#define TIME_STAMP						(0x00000134/sizeof(int))
#define TARGET_BITS						(0x00000138/sizeof(int))
#define PRE_HEADER_HASH					(0x00000140/sizeof(int))

//FPGA registers bit map
//QN_WRITE_DATA_COMMAND
#define RESET_HASH_BOARD				(1 << 31)
#define RESET_ALL						(1 << 23)
#define CHAIN_ID(id)					(id << 16)
#define RESET_FPGA						(1 << 15)
#define RESET_TIME(time)				(time << 0)
#define TIME_OUT_VALID					(1 << 31)
//RETURN_NONCE
#define WORK_ID_OR_CRC					(1 << 31)
#define WORK_ID_OR_CRC_VALUE(value)		((value >> 16) & 0x7fff)
#define NONCE_INDICATOR					(1 << 7)
#define CHAIN_NUMBER(value)				(value & 0xf)
#define REGISTER_DATA_CRC(value)		((value >> 24) & 0x7f)
//BC_WRITE_COMMAND
#define BC_COMMAND_BUFFER_READY			(1 << 31)
#define BC_COMMAND_EN_CHAIN_ID			(1 << 23)
#define BC_COMMAND_EN_NULL_WORK			(1 << 22)
//NONCE2_AND_JOBID_STORE_ADDRESS
#define JOB_ID_OFFSET					(0x0/sizeof(int))
#define HEADER_VERSION_OFFSET			(0x4/sizeof(int))
#define NONCE2_L_OFFSET					(0x8/sizeof(int))
#define NONCE2_H_OFFSET					(0xc/sizeof(int))
#define MIDSTATE_OFFSET					0x20
//DHASH_ACC_CONTROL
#define VIL_MODE						(1 << 15)
#define VIL_MIDSTATE_NUMBER(value)		((value &0x0f) << 8)
#define NEW_BLOCK						(1 << 7)
#define RUN_BIT							(1 << 6)
#define OPERATION_MODE					(1 << 5)
//NONCE_FIFO_INTERRUPT
#define FLUSH_NONCE3_FIFO				(1 << 16)


//ASIC macro define
//ASIC register address
#define CHIP_ADDRESS			0x0
#define GOLDEN_NONCE_COUNTER	0x8
#define PLL_PARAMETER			0xc
#define START_NONCE_OFFSET		0x10
#define HASH_COUNTING_NUMBER	0x14
#define TICKET_MASK				0x18
#define MISC_CONTROL			0x1c
//ASIC command
#define SET_ADDRESS				0x1
#define SET_PLL_DIVIDER2		0x2
#define PATTERN_CONTROL			0x3
#define GET_STATUS				0x4
#define CHAIN_INACTIVE			0x5
#define SET_BAUD_OPS			0x6
#define SET_PLL_DIVIDER1		0x7
#define SET_CONFIG				0x8
#define COMMAND_FOR_ALL			0x80
//other ASIC macro define
#define MAX_BAUD_DIVIDER		26
#define DEFAULT_BAUD_DIVIDER	26
#define BM1385_CORE_NUM			50


//other FPGA macro define
#define TOTAL_LEN						0x160
#define FPGA_MEM_TOTAL_LEN				(16*1024*1024)	// 16M bytes
#define HARDWARE_VERSION_VALUE			0x55ff0501
#define NONCE2_AND_JOBID_STORE_SPACE	(2*1024*1024)	// 2M bytes
#define NONCE2_AND_JOBID_STORE_SPACE_ORDER	9			// for 2M bytes space
#define JOB_STORE_SPACE					(1 << 16)		// for 64K bytes space
#define JOB_START_SPACE					(1024*8)		// 8K bytes
#define JOB_START_ADDRESS_ALIGN			32				// JOB_START_ADDRESS need 32 bytes aligned
#define NONCE2_AND_JOBID_ALIGN			64				// NONCE2_AND_JOBID_STORE_SPACE need 64 bytes aligned
#define MAX_TIMEOUT_VALUE				0x1ffff			// defined in TIME_OUT_CONTROL
#define MAX_NONCE_NUMBER_IN_FIFO		0x1ff			// 511 nonce
#define NONCE_DATA_LENGTH				4				// 4 bytes
#define REGISTER_DATA_LENGTH			4				// 4 bytes
#define TW_WRITE_COMMAND_LEN			52
#define NEW_BLOCK_MARKER				0x11
#define NORMAL_BLOCK_MARKER				0x01
#define PHY_MEM_NONCE2_JOBID_ADDRESS	((1024-16)*1024*1024)
#define PHY_MEM_JOB_START_ADDRESS_1		(PHY_MEM_NONCE2_JOBID_ADDRESS + NONCE2_AND_JOBID_STORE_SPACE)
#define PHY_MEM_JOB_START_ADDRESS_2		(PHY_MEM_JOB_START_ADDRESS_1 + JOB_STORE_SPACE)

// macro define about miner
#define BITMAIN_MAX_CHAIN_NUM			16 
#define BITMAIN_MAX_FAN_NUM				8				// FPGA just can supports 8 fan
#define BITMAIN_DEFAULT_ASIC_NUM		64				// max support 64 ASIC on 1 HASH board
#define MIDSTATE_LEN					32
#define MAX_RETURNED_NONCE_NUM			10
#define PREV_HASH_LEN					32
#define MERKLE_BIN_LEN					32
#define INIT_CONFIG_TYPE				0x51
#define	STATUS_DATA_TYPE				0xa1
#define SEND_JOB_TYPE					0x52
#define READ_JOB_TYPE					0xa2
#define CHECK_SYSTEM_TIME_GAP			10000			// 10s
//fan
#define MIN_PWM_PERCENT					20
#define MAX_PWM_PERCENT					100
#define TEMP_INTERVAL					2	
#define PWM_ADJUST_FACTOR				((100 - MIN_PWM_PERCENT)/(60-35))	
#define PWM_SCALE						50	
#define PWM_ADJ_SCALE					9/10
//use for hash test
#define TEST_DHASH 0
#define DEVICE_DIFF 5
//use for status check
#define RED_LED_DEV "/sys/class/leds/hps_led2/brightness"
#define GREEN_LED_DEV "/sys/class/leds/hps_led0/brightness"
#define MAX_TEMP 80


struct init_config {
	uint8_t 	token_type;
	uint8_t 	version;
	uint16_t	length;
	uint8_t		reset					:1;
	uint8_t		fan_eft					:1;
	uint8_t		timeout_eft				:1;
	uint8_t		frequency_eft			:1;
	uint8_t		voltage_eft				:1;
	uint8_t		chain_check_time_eft	:1;
	uint8_t		chip_config_eft			:1;
	uint8_t		hw_error_eft			:1;
	uint8_t		beeper_ctrl				:1;
	uint8_t		temp_ctrl				:1;
	uint8_t		chain_freq_eft			:1;
	uint8_t		reserved1				:5;
	uint8_t		reserved2[2];
	uint8_t		chain_num;
	uint8_t		asic_num;
	uint8_t		fan_pwm_percent;
	uint8_t		temperature;
	uint16_t	frequency;
	uint8_t		voltage[2];
	uint8_t		chain_check_time_integer;
	uint8_t		chain_check_time_fractions;
	uint8_t		timeout_data_integer;
	uint8_t		timeout_data_fractions;
	uint32_t	reg_data;
	uint8_t		chip_address;
	uint8_t		reg_address;
	uint16_t	chain_min_freq;
	uint16_t	chain_max_freq;
	uint16_t	crc;
} __attribute__((packed, aligned(4)));



struct bitmain_c5_info {
	cglock_t update_lock;
	
	uint8_t		data_type;
	uint8_t		version;
	uint16_t	length;
	uint8_t		chip_value_eft	:1;
	uint8_t		reserved1		:7;
	uint8_t		chain_num;
	uint16_t	reserved2;
	uint8_t		hw_version[4];
	uint8_t		fan_num;
	uint8_t		temp_num;
	uint8_t		reserved3[2];
	uint32_t	fan_exist;
	uint32_t	temp_exist;
	uint16_t	diff;
	uint16_t	reserved4;
	uint32_t	reg_value;
	uint32_t	chain_asic_exist[BITMAIN_MAX_CHAIN_NUM][BITMAIN_DEFAULT_ASIC_NUM/32];
	uint32_t	chain_asic_status[BITMAIN_MAX_CHAIN_NUM][BITMAIN_DEFAULT_ASIC_NUM/32];
	uint8_t		chain_asic_num[BITMAIN_MAX_CHAIN_NUM];
	uint8_t		temp[BITMAIN_MAX_CHAIN_NUM];
	uint8_t		fan_speed_value[BITMAIN_MAX_FAN_NUM];
	uint16_t	freq[BITMAIN_MAX_CHAIN_NUM];
	struct thr_info *thr;
	pthread_t read_nonce_thr;
	pthread_mutex_t lock;

	struct init_config c5_config;
	int pool_no;
	struct pool pool0;
	struct pool pool1;
	struct pool pool2;
	uint32_t pool0_given_id;
	uint32_t pool1_given_id;
	uint32_t pool2_given_id;

	uint16_t	crc;
} __attribute__((packed, aligned(4)));

struct part_of_job {
	uint8_t		token_type;				// buf[0]
	uint8_t		version;
	uint16_t	reserved;
	uint32_t	length;					// buf[1]
	uint8_t		pool_nu;				// buf[2]
	uint8_t		new_block		:1;
	uint8_t		asic_diff_valid	:1;
	uint8_t		reserved1		:6;
	uint8_t		asic_diff;
	uint8_t		reserved2[1];
	uint32_t	job_id;					// buf[3]
	uint32_t	bbversion;				// buf[4]
	uint8_t		prev_hash[32];			// buf[5] - buf[12]
	uint32_t	ntime;					// buf[13]
	uint32_t	nbit;					// buf[14]
	uint16_t	coinbase_len;			// buf[15]
	uint16_t	nonce2_offset;	
	uint16_t	nonce2_bytes_num;		// 4 or 8 bytes	// buf[16]
	uint16_t	merkles_num;
	uint64_t	nonce2_start_value;	//nonce2 start calculate value.	// buf[17] - buf[18]
};
	//uint8_t	coinbase						//this is variable
	//uint8_t	merkle_bin[32] * merkles_num
	//uint16_t	crc
	
struct nonce_content {
	uint32_t	job_id;
	uint32_t	work_id;
	uint32_t	header_version;
	uint64_t	nonce2;
	uint32_t	nonce3;
	uint32_t	chain_num;
	uint8_t		midstate[MIDSTATE_LEN];
} __attribute__((packed, aligned(4)));

struct nonce {
	uint8_t		token_type;
	uint8_t		version;
	uint16_t	length;
	uint16_t	valid_nonce_num;
	struct nonce_content nonce_cont[MAX_RETURNED_NONCE_NUM];
	uint16_t	crc;
} __attribute__((packed, aligned(4)));

struct all_parameters {
	
	unsigned int	*current_job_start_address;
	unsigned int	pwm_value;
	unsigned int	chain_exist[BITMAIN_MAX_CHAIN_NUM];
	unsigned int	timeout;
	unsigned int	fan_exist_map;
	unsigned int	temp_sensor_map;
	unsigned int	nonce_error;
	unsigned int	chain_asic_exist[BITMAIN_MAX_CHAIN_NUM][8];
	unsigned int	chain_asic_status[BITMAIN_MAX_CHAIN_NUM][8];
	uint64_t		chain_hw[BITMAIN_MAX_CHAIN_NUM];
	uint64_t		chain_asic_nonce[BITMAIN_MAX_CHAIN_NUM][BITMAIN_DEFAULT_ASIC_NUM];
	char			chain_asic_status_string[BITMAIN_MAX_CHAIN_NUM][BITMAIN_DEFAULT_ASIC_NUM+10];
	
	unsigned long long int total_nonce_num;

	unsigned char	fan_exist[BITMAIN_MAX_FAN_NUM];
	unsigned int	fan_speed_value[BITMAIN_MAX_FAN_NUM];
	int				temp[BITMAIN_MAX_CHAIN_NUM];
	unsigned char	chain_asic_num[BITMAIN_MAX_CHAIN_NUM];
	unsigned char	check_bit;
	unsigned char	pwm_percent;
	unsigned char	chain_num;
	unsigned char	fan_num;
	unsigned char	temp_num;
	int				temp_top1;
	int				temp_top1_last;
	unsigned char	corenum;
	unsigned char	addrInterval;
	unsigned char	max_asic_num_in_one_chain;
	unsigned char	baud;
	unsigned char	diff;
	
	unsigned short int	frequency;
	char frequency_t[10];
	unsigned short int	freq[BITMAIN_MAX_CHAIN_NUM];
} __attribute__((packed, aligned(4)));

volatile struct nonce_buf {
	unsigned int p_wr;
	unsigned int p_rd;
	unsigned int nonce_num;
	unsigned int loop_back;
	pthread_mutex_t spinlock;	
	struct nonce_content nonce_buffer[MAX_NONCE_NUMBER_IN_FIFO];
};

struct reg_content {
	unsigned int reg_value;
	unsigned char crc;
	unsigned char chain_number;
} __attribute__((packed, aligned(4)));

volatile struct reg_buf {
	unsigned int p_wr;
	unsigned int p_rd;
	unsigned int reg_value_num;
	unsigned int loop_back;
	pthread_mutex_t spinlock;	
	struct reg_content reg_buffer[MAX_NONCE_NUMBER_IN_FIFO];
};

struct freq_pll
{
	const char *freq;
	unsigned int fildiv1;
	unsigned int fildiv2;
	unsigned int vilpll;
};

#define Swap32(l) (((l) >> 24) | (((l) & 0x00ff0000) >> 8) | (((l) & 0x0000ff00) << 8) | ((l) << 24))  




static struct freq_pll freq_pll_1385[] = {
	{"100",0x020040, 0x0420, 0x200241},
	{"125",0x028040, 0x0420, 0x280241},
	{"150",0x030040, 0x0420, 0x300241},
	{"175",0x038040, 0x0420, 0x380241},
	{"200",0x040040, 0x0420, 0x400241},
	{"225",0x048040, 0x0420, 0x480241},
	{"250",0x050040, 0x0420, 0x500241},
	{"275",0x058040, 0x0420, 0x580241},
	{"300",0x060040, 0x0420, 0x600241},
	{"325",0x068040, 0x0420, 0x680241},
	{"350",0x070040, 0x0420, 0x700241},
	{"375",0x078040, 0x0420, 0x780241},
	{"400",0x080040, 0x0420, 0x800241},
	{"404",0x061040, 0x0320, 0x610231},
	{"406",0x041040, 0x0220, 0x410221},
	{"408",0x062040, 0x0320, 0x620231},
	{"412",0x042040, 0x0220, 0x420221},
	{"416",0x064040, 0x0320, 0x640231},
	{"418",0x043040, 0x0220, 0x430221},
	{"420",0x065040, 0x0320, 0x650231},
	{"425",0x044040, 0x0220, 0x440221},
	{"429",0x067040, 0x0320, 0x670231},
	{"431",0x045040, 0x0220, 0x450221},
	{"433",0x068040, 0x0320, 0x680231},
	{"437",0x046040, 0x0220, 0x460221},
	{"441",0x06a040, 0x0320, 0x6a0231},
	{"443",0x047040, 0x0220, 0x470221},
	{"445",0x06b040, 0x0320, 0x6b0231},
	{"450",0x048040, 0x0220, 0x480221},
	{"454",0x06d040, 0x0320, 0x6d0231},
	{"456",0x049040, 0x0220, 0x490221},
	{"458",0x06e040, 0x0320, 0x6e0231},
	{"462",0x04a040, 0x0220, 0x4a0221},
	{"466",0x070040, 0x0320, 0x700231},
	{"468",0x04b040, 0x0220, 0x4b0221},
	{"470",0x071040, 0x0320, 0x710231},
	{"475",0x04c040, 0x0220, 0x4c0221},
	{"479",0x073040, 0x0320, 0x730231},
	{"481",0x04d040, 0x0220, 0x4d0221},
	{"483",0x074040, 0x0320, 0x740231},
	{"487",0x04e040, 0x0220, 0x4e0221},
	{"491",0x076040, 0x0320, 0x760231},
	{"493",0x04f040, 0x0220, 0x4f0221},
	{"495",0x077040, 0x0320, 0x770231},
	{"500",0x050040, 0x0220, 0x500221},
	{"504",0x079040, 0x0320, 0x790231},
	{"506",0x051040, 0x0220, 0x510221},
	{"508",0x07a040, 0x0320, 0x7a0231},
	{"512",0x052040, 0x0220, 0x520221},
	{"516",0x07c040, 0x0320, 0x7c0231},
	{"518",0x053040, 0x0220, 0x530221},
	{"520",0x07d040, 0x0320, 0x7d0231},
	{"525",0x054040, 0x0220, 0x540221},
	{"529",0x07f040, 0x0320, 0x7f0231},
	{"531",0x055040, 0x0220, 0x550221},
	{"533",0x080040, 0x0320, 0x800231},
	{"537",0x056040, 0x0220, 0x560221},
	{"543",0x057040, 0x0220, 0x570221},
	{"550",0x058040, 0x0220, 0x580221},
	{"556",0x059040, 0x0220, 0x590221},
	{"562",0x05a040, 0x0220, 0x5a0221},
	{"568",0x05b040, 0x0220, 0x5b0221},
	{"575",0x05c040, 0x0220, 0x5c0221},
	{"581",0x05d040, 0x0220, 0x5d0221},
	{"587",0x05e040, 0x0220, 0x5e0221},
	{"593",0x05f040, 0x0220, 0x5f0221},
	{"600",0x060040, 0x0220, 0x600221},
	{"606",0x061040, 0x0220, 0x610221},
	{"612",0x062040, 0x0220, 0x620221},
	{"618",0x063040, 0x0220, 0x630221},
	{"625",0x064040, 0x0220, 0x640221},
	{"631",0x065040, 0x0220, 0x650221},
	{"637",0x066040, 0x0220, 0x660221},
	{"643",0x067040, 0x0220, 0x670221},
	{"650",0x068040, 0x0220, 0x680221},
	{"656",0x069040, 0x0220, 0x690221},
	{"662",0x06a040, 0x0220, 0x6a0221},
	{"668",0x06b040, 0x0220, 0x6b0221},
	{"675",0x06c040, 0x0220, 0x6c0221},
	{"681",0x06d040, 0x0220, 0x6d0221},
	{"687",0x06e040, 0x0220, 0x6e0221},
	{"693",0x06f040, 0x0220, 0x6f0221},
	{"700",0x070040, 0x0220, 0x700221},
	{"706",0x071040, 0x0220, 0x710221},
	{"712",0x072040, 0x0220, 0x720221},
	{"718",0x073040, 0x0220, 0x730221},
	{"725",0x074040, 0x0220, 0x740221},
	{"731",0x075040, 0x0220, 0x750221},
	{"737",0x076040, 0x0220, 0x760221},
	{"743",0x077040, 0x0220, 0x770221},
	{"750",0x078040, 0x0220, 0x780221},
	{"756",0x079040, 0x0220, 0x790221},
	{"762",0x07a040, 0x0220, 0x7a0221},
	{"768",0x07b040, 0x0220, 0x7b0221},
	{"775",0x07c040, 0x0220, 0x7c0221},
	{"781",0x07d040, 0x0220, 0x7d0221},
	{"787",0x07e040, 0x0220, 0x7e0221},
	{"793",0x07f040, 0x0220, 0x7f0221},
	{"800",0x080040, 0x0220, 0x800221},
	{"825",0x042040, 0x0120, 0x420211},
};

extern bool opt_bitmain_fan_ctrl;
extern int opt_bitmain_fan_pwm;
extern int opt_bitmain_c5_freq;
extern bool opt_bitmain_new_cmd_type_vil;

#endif

