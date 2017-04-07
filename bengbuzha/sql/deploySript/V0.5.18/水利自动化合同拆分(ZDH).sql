/****** Script for SelectTopNRows command from SSMS  ******/

--将非'%ZDH%'的合同转入到'监控事业部'
UPDATE  xmis.con_合同
SET     乙方部门ID = 1 ,
        备注 = '(工程一部转入)'+ISNULL(备注,'')
FROM    [xmis].[xmis].[con_合同] c
        LEFT JOIN xmis.prj_项目 p ON c.项目ID = p.项目ID
WHERE   p.项目编码 NOT LIKE '%ZDH%'
        AND c.乙方部门ID = 2
  
