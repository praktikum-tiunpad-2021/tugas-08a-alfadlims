#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T value;
  int priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> pNew = new Element<T>;
  pNew->value = value;
  pNew->priority = priority;
  pNew->next = nullptr;

  ElementPtr<T> pRev = nullptr;
  ElementPtr<T> pHelp = q.head;
  if(q.head == nullptr && q.tail == nullptr){
    q.head = pNew;
    q.tail = pNew;
  }else{
    while(pNew->priority <= pHelp->priority){
      if(pHelp->next == nullptr)
        break;
      pRev = pHelp;
      pHelp = pHelp->next;
    }

    if(pHelp == q.head && pNew->priority > pHelp->priority){
      pNew->next = pHelp;
      q.head = pNew;
    }else if(pHelp == q.tail && pNew->priority < pHelp->priority){
      pHelp->next = pNew;
      q.tail = pNew;
    }else{
      pRev->next = pNew;
      pNew->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head->value;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> pDel = nullptr;
  if(q.head == nullptr && q.tail == nullptr){
    std::cout << "Queue Kosong" << std::endl;
  }else if(q.head->next == nullptr){
    pDel = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }else{
    pDel = q.head;
    q.head = q.head->next;
    pDel->next = nullptr;
  }

  delete pDel;
}

}  // namespace priority_queue

}  // namespace strukdat
