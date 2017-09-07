#ifndef _PACKET_H_
#define _PACKET_H_
#include "commondef.h"
#include "tr1def.h"
struct BinaryData
{
	Byte*  pData;
	UInt16 uLength;
	BinaryData()
		: pData(NULL)
		, uLength(0)
	{
	
	}
};
struct PacketData;
class Packet
{
public:
	Packet();
	~Packet();
	////////////////////////////////////////////////////////////////////////////
	/// 操作表单数据(默认)
	void HandleTableData();
	/// 需操作Key-Value数据, 先调用此接口
	void HandleKeyValueData();
	////////////////////////////////////////////////////////////////////////////
	/// 指定添加表单下一行的数据(需当前行数据填充完, 否则调用失败)
	bool WriteNextRow();
	/// SetCurrentRowNo, ReSetCurrentRowNo, NextRow只能操作已存在的行
	/// 获取表单下一行的数据, 可调用此接口指定操作的行是下一行
	bool NextRow();
	/// 获取/修改表单某行的数据, 可调用此接口指定操作行的行号(从第0行开始) 
	bool SetCurrentRowNo(UInt16 uRowNo);
	/// 重置表单当前操作行为第0行
	void ReSetCurrentRowNo();
	////////////////////////////////////////////////////////////////////////////
	/// 获取表单数据行数
	UInt16 GetRowNumber();
	/// 获取表单数据列数
	UInt16 GetFieldNumber();
	/// 获取Key-Value数据数目
	UInt16 GetKeyValueNumber();
	////////////////////////////////////////////////////////////////////////////
	void SetByte(UInt32 uKeyID, Byte bValue);
	void SetChar(UInt32 uKeyID, char cValue);
	void SetInt16(UInt32 uKeyID, Int16 nValue);
	void SetUInt16(UInt32 uKeyID, UInt16 uValue);
	void SetInt32(UInt32 uKeyID, Int32 nValue);
	void SetUInt32(UInt32 uKeyID, UInt32 uValue);
	void SetInt64(UInt32 uKeyID, Int64 nValue);
	void SetUInt64(UInt32 uKeyID, UInt64 uValue);
	/// cstrValue如果传NULL, 设置失败
	void SetString(UInt32 uKeyID, const char* cstrValue);
	/// bData如果传NULL, 设置失败
	void SetBinaryData(UInt32 uKeyID, Byte* bData, UInt16 uLength); 
	////////////////////////////////////////////////////////////////////////////
	Byte GetByte(UInt32 uKeyID);
	char GetChar(UInt32 uKeyID);
	Int16 GetInt16(UInt32 uKeyID);
	UInt16 GetUInt16(UInt32 uKeyID);
	Int32 GetInt32(UInt32 uKeyID);
	UInt32 GetUInt32(UInt32 uKeyID);
	Int64 GetInt64(UInt32 uKeyID);
	UInt64 GetUInt64(UInt32 uKeyID);
	const char* GetString(UInt32 uKeyID);
	/// 返回的数据的内存由Packet释放, 不可对BinaryData的pData做释放内存操作
	BinaryData GetBinaryData(UInt32 uKeyID);
	////////////////////////////////////////////////////////////////////////////
	bool Deserialize(Byte* bData, UInt16 uLength); 
	/// 返回的数据的内存由Packet释放, 不可对BinaryData的pData做释放内存操作
	const BinaryData Serializable();
	////////////////////////////////////////////////////////////////////////////
	int CheckPacketError();
	////////////////////////////////////////////////////////////////////////////
	static const char* GetErrorMessage(int errorCode);
private:
	Packet(const Packet&);
	Packet& operator =(const Packet&);
	PacketData* pPacketData_;
};
typedef stdtr1::shared_ptr<Packet> PacketReference;
#endif // _PACKET_H_
