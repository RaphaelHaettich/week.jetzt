const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.join(__dirname, 'build/');
const ExtractTextPlugin = require("extract-text-webpack-plugin");
const extractStyle = new ExtractTextPlugin({ filename: "index.css" });

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: {
    index: ["./src/Index.bs.js", "./src/index.scss"]
  },
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'Index.js'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'src/index.html',
      inject: false
    }),
    extractStyle
  ],
  module: {
    rules: [
      {
        test: /\.(scss|css)$/,
        use: extractStyle.extract({
          use: [
            {
              loader: "css-loader"
            },
            {
              loader: "sass-loader"
            }
          ]
        })
      }
    ]
  },
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  }
};
