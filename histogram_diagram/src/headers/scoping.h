#ifndef ARAD_SCOPING_SCOPINGCLS_SCOPING_H
#define ARAD_SCOPING_SCOPINGCLS_SCOPING_H

#include <QTextStream>
#include <QVector>
#include <QMap>
#include <QList>

namespace Arad
{

    namespace Scoping
    {

        class ScopingCls
        {
        public:
            ScopingCls(QString const& filePath, QString const& delimiter, QVector<uint32_t> const& spamLines,
                    int columnNumber, uint32_t range /* range of scopes in histogram diagram */ );
            
            ScopingCls() = delete;
            virtual ~ScopingCls() = default;

            QVector<QVector<float>> const& getRangedVector() const;
            
            void setMap(QMap<double, QString> const&);
            QMap<double, QString> const& getMap() const;
            
            void setLabelList(QList<QString> const& labelList);
            QList<QString> const& getLabelList() const;
    
        private:        
            /// the following nested vector will store ranged information
            QVector<QVector<float>> _rangedVector;
            
            
            /// the following map stores index number of the _rangedVector
            /// and the related text to it 
            /// (e.g. index: 1, related text: 64-73 (this text shows the range))
            QMap<double, QString> _mapper;
            
            /// this variable list stores range string (like _mapper but only stores
            /// range string and doesn't stores any index for the range string)
            QList<QString> _labelList;
        };
    
    } // Scoping namespace

} // Arad namespace

#endif  // ARAD_SCOPING_SCOPINGCLS_SCOPING_H