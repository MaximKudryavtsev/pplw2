// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <random>
#include <exception>
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <memory>
#include <numeric>  
#include <functional>
#include <iterator>
#include <cassert> 
#include <algorithm>
#include <mutex>
#include <deque> 

const unsigned TWISTING_TIME = 500u;
const unsigned SMOKING_TIME = 500u;

#include "Event.h"
#include "Smoker.h"
#include "Mediator.h"
#include "ThreadHandler.h"
#include "Table.h"


// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
