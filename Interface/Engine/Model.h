#pragma once

#include <map>
#include <string>

using std::map;
using std::string;

/*	Data encapsulated interface */
class IModel
{
public:
	IModel();
	virtual ~IModel(){}

	/* get unique IModel instance ID */
	virtual unsigned int	getId()		const	= 0;

	/* get instance tag/name */
	virtual string			getTag()	const	= 0;

	/* get type hash code */
	virtual size_t			getType()	const	= 0;

protected:
	unsigned int	m_lazy_id;
};

/*	Templated IModel object
	- can point hold any type of data
	- data will only be assigned on creation */
template<typename T>
class CModel
	: public IModel
{
public:
	CModel(string _tag, T* _dataPtr)
		: m_tag(_tag), m_pDataPtr(_dataPtr)
	{ }

	~CModel()
	{
		if(m_pDataPtr)
			delete m_pDataPtr;
	}

	/* get unique IModel instance ID */
	unsigned int getId() const override
	{ return m_lazy_id; }

	/* get instance tag */
	string getTag() const override
	{ return m_tag; }

	/* get T hash code */
	size_t getType() const override
	{ return typeid(T).hash_code(); }

	/* get T ptr */
	T* getDataPtr()
	{ return m_pDataPtr; }

	//void setDataPtr(T* _dataPtr)
	//{ m_dataPtr = _dataPtr; }

private:
	string			m_tag;
	T*				m_pDataPtr;
};

/*	Object composed of unique CModel types
	- will take any CModel-encapsulated data but only one instance per type */
class Composition
{
public:
	Composition();

	~Composition()
	{}

	/*	Set type property ptr
		#_data: CModel<T> ptr

		returns:
			true (if type is unique)
			false (if else)	*/
	template<typename T>
	bool setProperty(CModel<T>* _data)
	{ 
		if( m_properties.count( typeid(CModel<T>*).hash_code()) == 0)	// don't overwrite already exisitng data
		{
			m_properties[ typeid(CModel<T>*).hash_code() ] = _data;
		}
		else return false;

		return true;
	}

	/*	Get type property ptr
		returns:
			* explicit T ptr (if type exist)
			* nullptr (if type doesn't exist)	*/
	template<typename T>
	T* getProperty()
	{
		if( m_properties.count( typeid(CModel<T>*).hash_code() ) > 0)	// make sure the property actually exist
		{
			return static_cast<CModel<T>*>(m_properties[ typeid(CModel<T>*).hash_code() ])->getDataPtr();
		}
		else return nullptr;
	}

	/* set name for object */
	void setName(string _name)
	{ m_name = _name; }

	/* get name of object */
	string getName()
	{ return m_name; }

	/* get unique composition instance ID */
	unsigned int getId()
	{ return m_id; }

	bool isSelected()
	{ return m_isSelected; }

	void setSelected(bool _toggle)
	{ m_isSelected = _toggle; }

private:
	map< size_t, IModel* >	m_properties;
	string					m_name;
	unsigned int			m_id;
	bool					m_isSelected;
};
