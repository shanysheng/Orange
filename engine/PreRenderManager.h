/*
 * Copyright 2017 sheng chongshan. All rights reserved.
 * email: shany.sheng@qq.com
 * License: https://github.com/shanysheng/RenderPipeline/blob/master/LICENSE
 */


#ifndef PIPELINE_PRERENDERMANAGER_H_GUARD
#define PIPELINE_PRERENDERMANAGER_H_GUARD

#include "Common.h"
#include "IPreRender.h"

namespace pipeline{
    
    class IPreRender;
    class CRenderingEngine;
    
    class CPreRenderManager
    {
    public:
        CPreRenderManager();
        virtual ~CPreRenderManager();
        
        void		Register(const std::string& PrototypeName, IPreRender* pPrototype);
        
        IPreRender* Give( const std::string& PreRenderMame, const std::string& PrototypeName);
        IPreRender* operator [] (const std::string& PreRenderName);
        
        void		ClearPrototypes();
        void		ClearPreRenders();
        
    protected:
        
        std::unordered_map<std::string, IPreRender*> m_Prototypes;
        std::unordered_map<std::string, IPreRender*> m_PreRenders;
    };
    
}

#endif
