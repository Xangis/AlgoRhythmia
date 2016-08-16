
#ifndef UTIL_ITERATOR_H
#define UTIL_ITERATOR_H

#include <vector>
#include <map>

template <typename ItemType> 
class ConstVectorIterator {

    public:
        typedef std::vector<ItemType> ItemArray;
        typedef const typename ItemArray::value_type  ValueRef;
        typedef const typename ItemArray::value_type* ValuePtr;
        typedef typename ItemArray::const_iterator STLVectorIterator;

        ConstVectorIterator() {}
        ConstVectorIterator(STLVectorIterator i) : v_iter(i) {}
        ConstVectorIterator(const ConstVectorIterator& i) : v_iter(i.v_iter) {}

        ConstVectorIterator& operator=(ConstVectorIterator i) {
            v_iter = i.v_iter;
            return (*this);
        }

		ValueRef& operator*() const {
		    return (*v_iter);
	    }

        ValuePtr operator->() const {
            return &(*v_iter);
        }

	    ConstVectorIterator& operator++() {
            v_iter++;
		    return (*this);
	    }

	    ConstVectorIterator operator++(int) {
		    ConstVectorIterator temp = (*this);
		    ++(*this);
		    return (temp);
	    }

	    ConstVectorIterator& operator--() {
            v_iter--;
		    return (*this);
	    }

	    ConstVectorIterator operator--(int) {
		    ConstVectorIterator temp = (*this);
		    --(*this);
		    return (temp);
	    }

	    bool operator !=(const ConstVectorIterator& right) {
		    return (this->v_iter != right.v_iter);
	    }

	    bool operator ==(const ConstVectorIterator& right) {
		    return (this->v_iter == right.v_iter);
	    }

    private:
        STLVectorIterator v_iter;
};

template <typename Key, typename Value> 
class ConstMapIterator {

    public:
        typedef std::map<Key, Value> KeyValueMap;
        typedef const typename KeyValueMap::value_type  ValueRef;
        typedef const typename KeyValueMap::value_type* ValuePtr;
        typedef typename KeyValueMap::const_iterator STLMapIterator;

        ConstMapIterator() {}
        ConstMapIterator(STLMapIterator i) : m_iter(i) {}
        ConstMapIterator(const ConstMapIterator& i) : m_iter(i.m_iter) {}

        ConstMapIterator& operator=(ConstMapIterator i) {
            m_iter = i.m_iter;
            return (*this);
        }

		ValueRef& operator*() const {
		    return (*m_iter);
	    }

        ValuePtr operator->() const {
            return &(*m_iter);
        }

	    ConstMapIterator& operator++() {
            m_iter++;
		    return (*this);
	    }

	    ConstMapIterator operator++(int) {
		    ConstMapIterator temp = (*this);
		    ++(*this);
		    return (temp);
	    }

	    ConstMapIterator& operator--() {
            m_iter--;
		    return (*this);
	    }

	    ConstMapIterator operator--(int) {
		    ConstMapIterator temp = (*this);
		    --(*this);
		    return (temp);
	    }

	    bool operator !=(const ConstMapIterator& right) {
		    return (this->m_iter != right.m_iter);
	    }

	    bool operator ==(const ConstMapIterator& right) {
		    return (this->m_iter == right.m_iter);
	    }

    private:
        STLMapIterator m_iter;
};

template <typename Key, typename Value> 
class ConstMapKeyIterator {

    public:
        typedef std::map<Key, Value> KeyValueMap;
        typedef const typename KeyValueMap::key_type  KeyRef;
        typedef const typename KeyValueMap::key_type* KeyPtr;
        typedef typename KeyValueMap::const_iterator STLMapIterator;

        ConstMapKeyIterator() {}
        ConstMapKeyIterator(STLMapIterator i) : m_iter(i) {}
        ConstMapKeyIterator(const ConstMapKeyIterator& i) : m_iter(i.m_iter) {}

        ConstMapKeyIterator& operator=(ConstMapKeyIterator i) {
            m_iter = i.m_iter;
            return (*this);
        }

		const Key& operator*() const {
		    return (*m_iter).first;
	    }

        //KeyPtr operator->() const {
        //    return &(*m_iter).first;
        //}

	    ConstMapKeyIterator& operator++() {
            m_iter++;
		    return (*this);
	    }

	    ConstMapKeyIterator operator++(int) {
		    ConstMapKeyIterator temp = (*this);
		    ++(*this);
		    return (temp);
	    }

	    ConstMapKeyIterator& operator--() {
            m_iter--;
		    return (*this);
	    }

	    ConstMapKeyIterator operator--(int) {
		    ConstMapKeyIterator temp = (*this);
		    --(*this);
		    return (temp);
	    }

	    bool operator !=(const ConstMapKeyIterator& right) {
		    return (this->m_iter != right.m_iter);
	    }

	    bool operator ==(const ConstMapKeyIterator& right) {
		    return (this->m_iter == right.m_iter);
	    }

    private:
        STLMapIterator m_iter;
};

#endif
