#include "unity.h"
#include "linkedlist.h"
#include "project1.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_listInit_ensure_initialized_to_NULL_and_0 (void)
{
  LinkedList list = {
    (Item *)-1,
    (Item *)-1,
    10
  };
  
  listInit(&list);
  
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  TEST_ASSERT_EQUAL(0,list.head);
}

void test_listAdd_given_an_empty_linked_list_then_add_ali_expect_1_item_in_list(void)
{
  LinkedList list;
  Student ali = { 
  "Ali",              // name
  23,                 // age
  70.5,               // weight
  1.78                // height
  };
  
  Item item = {
    (Item *)-1,       //next
    (void *)&ali      //data
  };
  listInit(&list);
  listAdd(&list,&item);
  TEST_ASSERT_EQUAL_PTR(&item,list.head);
  TEST_ASSERT_EQUAL_PTR(&item,list.tail);
  TEST_ASSERT_EQUAL(1,list.len);
  TEST_ASSERT_NULL(item.next);
  TEST_ASSERT_EQUAL_PTR(&ali,item.data);
}

void test_ali_and_baba(void)
{
  LinkedList list;
 
  Student ali = { 
  "Ali",               // name
  23,                  // age
  70.5,                // weight
  1.78                 // height
  };
  
  Student baba = { 
  "Baba",              // name
  25,                  // age
  72.5,                // weight
  1.88                 // height
  };
  
  Item itemali = {
    (Item *)-1,        // next
    (void *)&ali       // data
  };
  Item itembaba = {
    (Item *)-1,        // next
    (void *)&baba      // data
  };
  list.head = &itemali;
  list.tail = &itemali;
  list.len = 1;
  itemali.next = &itembaba;
  itembaba.next = (Item *)-1;
  listAdd(&list,&itembaba);
  TEST_ASSERT_EQUAL_PTR(&itemali,list.head);
  TEST_ASSERT_EQUAL(2,list.len);
  TEST_ASSERT_EQUAL_PTR(&itembaba,itemali.next);
  TEST_ASSERT_NULL(itembaba.next);
  TEST_ASSERT_EQUAL_PTR(&baba,itembaba.data);
}