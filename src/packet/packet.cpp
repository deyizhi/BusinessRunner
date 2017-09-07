#include "packet.h"
#include <string>
#include "hashmap_extenddef.h"

/// 表示数据类型
enum DataType
{
  UNDEF_MIN_TYPE = 0,
  CHAR_TYPE = 1,
  BYTE_TYPE = 2,
  INT16_TYPE = 3,
  UINT16_TYPE = 4,
  INT32_TYPE = 5,
  UINT32_TYPE = 6,	
  INT64_TYPE = 7,
  UINT64_TYPE = 8,	
  STRING_TYPE = 9,
  BINARY_TYPE = 10,
  UNDEF_MAX_TYPE = 11,
}

/// 不定长整形
union VariableLengthInterger
{
	char		cValue;
	Byte		bValue;
	Int16		n16Value;
	UInt16		u16Value;
	Int32		n32Value;
	UInt32		u32Value; 
	Int64		n64Value;
	UInt64		u64Value;
	VariableLengthData
	 : u64Value(0)
	{
	}
};

#pragma pack(push,1) 
/// 不定长的整形值
struct VarValue
{
	VariableLengthInterger  interger;
	DataType				type;
	VarValue()
		: type(UNDEF_MIN_TYPE)
	{
	}
}
#pragma pack(pop) 

////////////////////////////////////////////////////////////////////////////
typedef	hash_map<uInt32, VarValue> 	  IntergerValueMap;
typedef	hash_map<uInt32, std::string> StringValueMap;
typedef	hash_map<uInt32, BinaryData>  BinaryValueMap;
////////////////////////////////////////////////////////////////////////////
/// 表示Packet的一行的数据
struct RowData
{
	IntergerValueMap  intergerMap;
	StringValueMap    stringMap;
	BinaryValueMap    binaryMap;
	UInt16 GetItemCount()
	{
		return intergerMap.size() + stringMap.size() + binaryMap.size();
	}
};
typedef stdtr1::shared_ptr<RowData> RowDataReference;
////////////////////////////////////////////////////////////////////////////
/// fieldID和类型关系
struct FieldIDWithType
{
	DataType type;
	UInt32	 fieldID;
	FieldIDWithType(DataType dataType, UInt32 uFieldID)
		: type(dataType)
		, fieldID(uFieldID)
	{
		
	}
}

/// 表示Packet的数据
struct PacketData
{
	std::vector<FieldIDWithType>    fields;				///< 表单的field和类型关系的集合
	std::vector<FieldIDWithType>    keys;				///< keyValue的Key和类型关系的集合
	std::vector<RowDataReference>  	tableRows;			///< 表单数据
	RowDataReference			 	keyValueData;		///< keyValue数据
	UInt16							currentRowNo;		///< 表单数据当前行号
	UInt16							writeRowNo;			///< 表单数据将写入的行
	BinaryData 		      			serializedData;		///< 序列化后的数据
	bool							isHandleTableData;	///< 是否操作表单数据
	PacketData()
		: currentRowNo(0)
		, writeRowNo(0)
		, isHandleTableData(true)
	{
		
	}
};

////////////////////////////////////////////////////////////////////////////
Packet::Packet()
	: pPacketData_(new PacketData)
{
	
}

Packet::~Packet()
{
	if (pPacketData_)
	{
		delete pPacketData_;
	}
}

void Packet::HandleTableData()
{
	pPacketData_->isHandleTableData = true;
}

void Packet::HandleKeyValueData()
{
	pPacketData_->isHandleTableData = false;
}

bool Packet::WriteNextRow()
{
	uInt16	rowNumber = pPacketData_->tableRows.size();
	if (pPacketData_->writeRowNo< rowNumber)
	{
		++pPacketData_->writeRowNo;
		return true;
	}	
	return  false;
}

bool Packet::NextRow()
{	
	uInt16	rowNumber = pPacketData_->tableRows.size();
	if (pPacketData_->currentRowNo< rowNumber-1)
	{
		++pPacketData_->currentRowNo;
		return true;
	}
	return false;
}

bool Packet::SetCurrentRowNo(UInt16 uRowNo)
{
	uInt16	rowNumber = pPacketData_->tableRows.size();
	if (uRowNo< rowNumber)
	{
		pPacketData_->currentRowNo = uRowNo;
		return true;
	}
	return false;
}

void Packet::ReSetCurrentRowNo()
{
	pPacketData_->currentRowNo = 0;
}

UInt16 Packet::GetRowNumber()
{
	return pPacketData_->tableRows.size();	
}

UInt16 Packet::GetFieldNumber()
{
	return pPacketData_->fields.size();	
}

UInt16 Packet::GetKeyValueNumber()
{
	return pPacketData_->keys.size();	
}

void Packet::SetByte(UInt32 uKeyID, Byte bValue)
{
	if (isHandleTableData)
	{
		if (0 == currentRowNo)
		{
			FieldIDWithType fieldIDWithType(BYTE_TYPE, uKeyID);
			
		}
		else
		{
			
		}
	}
	else
	{
		
	}
}

void Packet::SetChar(UInt32 uKeyID, char cValue)
{

}

void Packet::SetInt16(UInt32 uKeyID, Int16 nValue)
{

}

void Packet::SetInt32(UInt32 uKeyID, Int32 nValue)
{

}

void Packet::SetUInt32(UInt32 uKeyID, UInt32 uValue)
{

}

void Packet::SetInt64(UInt32 uKeyID, Int64 nValue)
{

}

void Packet::SetUInt64(UInt32 uKeyID, UInt64 uValue)
{

}

void Packet::SetString(UInt32 uKeyID, const char* cstrValue)
{

}

void Packet::SetBinaryData(UInt32 uKeyID, Byte* bData, UInt16 uLength)
{

}

Byte Packet::GetByte(UInt32 uKeyID)
{

}

char Packet::GetChar(UInt32 uKeyID)
{

}

Int16 Packet::GetInt16(UInt32 uKeyID)
{

}

UInt16 Packet::GetUInt16(UInt32 uKeyID)
{

}

Int32 Packet::GetInt32(UInt32 uKeyID)
{

}

UInt32 Packet::GetUInt32(UInt32 uKeyID)
{

}

Int64 Packet::GetInt64(UInt32 uKeyID)
{

}

UInt64 Packet::GetUInt64(UInt32 uKeyID)
{

}

const char* Packet::GetString(UInt32 uKeyID)
{

}

BinaryData Packet::GetBinaryData(UInt32 uKeyID)
{

}

bool Packet::Deserialize(Byte* bData, UInt16 uLength)
{

}

int Packet::CheckPacketError()
{

}

const BinaryData Packet::Serializable()
{

}

const char* Packet::GetErrorMessage(int errorCode)
{

}
