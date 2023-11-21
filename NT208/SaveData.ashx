<%@ WebHandler Language="C#" Class="SaveData" %>

using System;
using System.IO;
using System.Web;

public class SaveData : IHttpHandler
{
    public void ProcessRequest(HttpContext context)
    {
        string data = context.Request.Form["data"];

        // Thay đổi đường dẫn tệp tin nếu cần thiết
        string dataFilePath = context.Server.MapPath("data.txt");

        // Ghi dữ liệu vào tệp tin
        File.AppendAllText(dataFilePath, data);
    }

    public bool IsReusable
    {
        get { return false; }
    }
}
