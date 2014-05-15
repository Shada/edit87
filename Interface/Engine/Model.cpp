#include "Model.h"

/* This is not a good solution but I'm a lazy, lazy man */
static unsigned int Lazy_Model_Counter;
static unsigned int Lazy_Composition_Counter;

IModel::IModel()
	: m_lazy_id(Lazy_Model_Counter++)
{}

Composition::Composition()
	: m_id(Lazy_Composition_Counter++), m_isSelected(false)
{}