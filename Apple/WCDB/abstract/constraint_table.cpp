/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WCDB/constraint_table.hpp>
#include <WCDB/column_index.hpp>
#include <WCDB/expr.hpp>

namespace WCDB {

TableConstraint::TableConstraint()
: Describable("")
{
}

TableConstraint::TableConstraint(const char* name)
: Describable(std::string("CONSTRAINT ")+name)
{
}

TableConstraint::TableConstraint(const std::string& name)
: Describable("CONSTRAINT "+name)
{
}

TableConstraint& TableConstraint::onConflict(Conflict conflict)
{
    if (conflict!=WCDB::Conflict::NotSet) {
        m_description.append(" ON CONFLICT ");
        m_description.append(ConflictName(conflict));
    }
    return *this;
}

TableConstraint& TableConstraint::makeCheck(const Expr& expr)
{
    m_description.append(" CHECK ("+expr.getDescription()+")");
    return *this;
}
    
}//namespace WCDB
